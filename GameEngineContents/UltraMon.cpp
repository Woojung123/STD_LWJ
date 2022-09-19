

#include "PreCompile.h"
#include "UltraMon.h"
#include "StageMain.h"
#include "ZergDeath.h"
#include "MiniMapUnit.h"



#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

UltraMon::UltraMon()
	: Speed(100.0f)//100
	, Renderer(nullptr)
	, DeathEff(nullptr)
	
{
}

UltraMon::~UltraMon()
{
}



void UltraMon::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		GetTransform().SetWorldPosition({ -1348.f,617.f,0.f });

		Renderer->CreateFrameAnimationFolder("ultraMoveD", FrameAnimation_DESC("ultraMoveD", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("ultraMoveL", FrameAnimation_DESC("ultraMoveL", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("ultraMoveR", FrameAnimation_DESC("ultraMoveR", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("ultraMoveU", FrameAnimation_DESC("ultraMoveU", 0.1f, true));


		Renderer->ChangeFrameAnimation("ultraMoveD");

	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		GetTransform().SetWorldPosition({ -1348.f,617.f,0.f });

		ShadowRenderer->CreateFrameAnimationFolder("ultraMoveD", FrameAnimation_DESC("ultraMoveD", 0.1f, true));
		ShadowRenderer->CreateFrameAnimationFolder("ultraMoveL", FrameAnimation_DESC("ultraMoveL", 0.1f, true));
		ShadowRenderer->CreateFrameAnimationFolder("ultraMoveR", FrameAnimation_DESC("ultraMoveR", 0.1f, true));
		ShadowRenderer->CreateFrameAnimationFolder("ultraMoveU", FrameAnimation_DESC("ultraMoveU", 0.1f, true));


		ShadowRenderer->ChangeFrameAnimation("ultraMoveD");

		ShadowRenderer->GetPixelData().MulColor.r = 0.f;
		ShadowRenderer->GetPixelData().MulColor.g = 0.f;
		ShadowRenderer->GetPixelData().MulColor.b = 0.f;
		ShadowRenderer->GetPixelData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 5.f;
		SLocalPos.z += 1.f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);
	}

	{
		MonHPRenderer = CreateComponent<GameEngineTextureRenderer>();
		MonHPRenderer->SetTexture("Hpbar_4.png");
		MonHPRenderer->ScaleToTexture();
		MonHPRenderer->GetTransform().SetLocalPosition({ 0.f, -20.f, -50.f });
		MonHPRenderer->renderOption.Option00 = 1;
		MonHPRenderer->GetPixelData().Slice.x = 1;

	}

	{
		MonSHRenderer = CreateComponent<GameEngineTextureRenderer>();
		MonSHRenderer->SetTexture("Shield_4.png");
		MonSHRenderer->ScaleToTexture();
		MonSHRenderer->GetTransform().SetLocalPosition({ 0.f, -20.f, -55.f });
		MonSHRenderer->renderOption.Option00 = 1;
		MonSHRenderer->GetPixelData().Slice.x = 1;

	}

	{
		MonFRRenderer = CreateComponent<GameEngineTextureRenderer>();
		MonFRRenderer->SetTexture("Frame_4.png");
		MonFRRenderer->ScaleToTexture();
		MonFRRenderer->GetTransform().SetLocalPosition({ 0.f, -20.f, -40.f });
	}


	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Monster);
	}

	MiniUnit = GetLevel()->CreateActor<MiniMapUnit>(OBJECTORDER::UI);


}

void UltraMon::Update(float _DeltaTime)
{

	MiniUnit->UnitPos = GetTransform().GetWorldPosition();



	if ((m_Info.m_MaxHp / 2) <= m_Info.m_Hp)
	{

		float MHp = (float)(m_Info.m_MaxHp / 2);
		float NHp = (float)(m_Info.m_Hp - MHp);



		float HPLen = (NHp / MHp);// / 100.f;
		HPLen = HPLen;
		MonSHRenderer->GetPixelData().Slice.x = HPLen;

	}
	else
	{

		float HPLen = ((float)m_Info.m_Hp / (float)m_Info.m_MaxHp);// / 100.f;
		HPLen = HPLen + HPLen;
		MonHPRenderer->GetPixelData().Slice.x = HPLen;


	}



	if (m_Info.m_Hp <= 0)
	{
		DeathEff = GetLevel()->CreateActor<ZergDeath>(OBJECTORDER::Effect);
		DeathEff->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
		Death();
		MiniUnit->Death();

		if (m_bDiecheck)
		{
			--m_MainStage->Player_HP;
		}
		else
		{
			m_MainStage->Player_Gold += m_Info.Gold;

		}
	}


	Move(_DeltaTime);

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -20.f, WorldPos.w });


}

void UltraMon::Move(float _DeltaTime)
{
	float4 GoPoint;
	auto	iter = CheckPoint.begin();
	auto	iterEnd = CheckPoint.end();

	float4 WorldPos = GetTransform().GetWorldPosition();
	WorldPos.z = 1.f;
	for (; iter != iterEnd; ++iter)
	{

		if (iter->TurnCheck == true)
		{
			if ((int)(WorldPos.x + 3) > (int)(iter->TurnPoint.x) &&
				(int)(WorldPos.x - 3) < (int)(iter->TurnPoint.x)
				&& (int)(WorldPos.y - 3) < (int)(iter->TurnPoint.y)
				&& (int)(WorldPos.y + 3) > (int)(iter->TurnPoint.y))
			{
				iter->TurnCheck = false;

				if (iter->TurnPoint.x == -1105.f && iter->TurnPoint.y == 633.f)
				{
					m_bDiecheck = true;
					m_Info.m_Hp = -1;
				}
				break;


			}
			else
			{
				GoPoint = iter->TurnPoint;
				break;
			}
		}




	}


	m_Dir = (GoPoint - WorldPos);
	m_Dir.Normalize();


	GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);

	ChangeAni(GoPoint, WorldPos);


}

void UltraMon::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;


	if (m_fAngle >= 45.f && m_fAngle < 135.f)
	{
		Renderer->ChangeFrameAnimation("ultraMoveU");
		ShadowRenderer->ChangeFrameAnimation("ultraMoveU");
	}
	else if (m_fAngle >= 135.f && m_fAngle <= 225.f)
	{
		Renderer->ChangeFrameAnimation("ultraMoveL");
		ShadowRenderer->ChangeFrameAnimation("ultraMoveL");
	}
	else if (m_fAngle >= 225.f && m_fAngle <= 315.f)
	{
		Renderer->ChangeFrameAnimation("ultraMoveD");
		ShadowRenderer->ChangeFrameAnimation("ultraMoveD");
	}
	else if (m_fAngle >= 315.f || m_fAngle <= 45.f)
	{
		Renderer->ChangeFrameAnimation("ultraMoveR");
		ShadowRenderer->ChangeFrameAnimation("ultraMoveR");
	}



}
