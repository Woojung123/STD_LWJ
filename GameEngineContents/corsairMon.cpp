
#include "PreCompile.h"
#include "corsairMon.h"
#include "StageMain.h"
#include "ProDeath.h"
#include "MiniMapUnit.h"

#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>

corsairMon::corsairMon()
	: Speed(100.0f)//100
	, Renderer(nullptr)
	, DeathEff(nullptr)
	
{
}

corsairMon::~corsairMon()
{
}



void corsairMon::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });
		GetTransform().SetWorldPosition({ -1348.f,617.f,0.f });

		Renderer->CreateFrameAnimationFolder("corsairMoveD", FrameAnimation_DESC("corsairMoveD", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("corsairMoveL", FrameAnimation_DESC("corsairMoveL", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("corsairMoveR", FrameAnimation_DESC("corsairMoveR", 0.1f, true));
		Renderer->CreateFrameAnimationFolder("corsairMoveU", FrameAnimation_DESC("corsairMoveU", 0.1f, true));


		Renderer->ChangeFrameAnimation("corsairMoveD");

	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });
		GetTransform().SetWorldPosition({ -1348.f,617.f,0.f });

		ShadowRenderer->CreateFrameAnimationFolder("corsairMoveD", FrameAnimation_DESC("corsairMoveD", 0.1f, true));
		ShadowRenderer->CreateFrameAnimationFolder("corsairMoveL", FrameAnimation_DESC("corsairMoveL", 0.1f, true));
		ShadowRenderer->CreateFrameAnimationFolder("corsairMoveR", FrameAnimation_DESC("corsairMoveR", 0.1f, true));
		ShadowRenderer->CreateFrameAnimationFolder("corsairMoveU", FrameAnimation_DESC("corsairMoveU", 0.1f, true));


		ShadowRenderer->ChangeFrameAnimation("corsairMoveD");



		ShadowRenderer->GetPixelData().MulColor.r = 0.f;
		ShadowRenderer->GetPixelData().MulColor.g = 0.f;
		ShadowRenderer->GetPixelData().MulColor.b = 0.f;
		ShadowRenderer->GetPixelData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 25.f;
		SLocalPos.z += 0.5f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);

	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Monster);
	}


	{
		MonHPRenderer = CreateComponent<GameEngineTextureRenderer>();
		MonHPRenderer->SetTexture("Hpbar_4.png");
		MonHPRenderer->ScaleToTexture();
		MonHPRenderer->GetTransform().SetLocalPosition({0.f, -20.f, -50.f});
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


	MiniUnit = GetLevel()->CreateActor<MiniMapUnit>(OBJECTORDER::UI);

}

void corsairMon::Update(float _DeltaTime)
{
	


	if ((m_Info.m_MaxHp/2) <= m_Info.m_Hp)
	{

		float MHp = (float)(m_Info.m_MaxHp / 2);
		float NHp = (float)(m_Info.m_Hp - MHp);



		float HPLen = (NHp / MHp);// / 100.f;
		HPLen = HPLen;
		MonSHRenderer->GetPixelData().Slice.x = HPLen;

	}
	else
	{

		MonSHRenderer->GetPixelData().Slice.x = 0.f;


		float HPLen = ((float)m_Info.m_Hp / (float)m_Info.m_MaxHp);// / 100.f;
		HPLen = HPLen + HPLen;
		MonHPRenderer->GetPixelData().Slice.x = HPLen;


	}
	




//	float slicex = (HPLen * 1.5f);


	


	

	MiniUnit->UnitPos = GetTransform().GetWorldPosition();


	if (m_Info.m_Hp <= 0)
	{
		DeathEff = GetLevel()->CreateActor<ProDeath>(OBJECTORDER::Effect);
		DeathEff->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
		MiniUnit->Death();
		Death();


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



void corsairMon::Move(float _DeltaTime)
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

					m_Info.m_Hp = -1;
					m_bDiecheck = true;
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

void corsairMon::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;

	
	if (m_fAngle >= 45.f && m_fAngle < 135.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveU");
		ShadowRenderer->ChangeFrameAnimation("corsairMoveU");

	}
	else if (m_fAngle >= 135.f && m_fAngle <= 225.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveL");
		ShadowRenderer->ChangeFrameAnimation("corsairMoveL");
	}
	else if (m_fAngle >= 225.f && m_fAngle <= 315.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveD");
		ShadowRenderer->ChangeFrameAnimation("corsairMoveD");
	}
	else if (m_fAngle >= 315.f || m_fAngle <= 45.f)
	{
		Renderer->ChangeFrameAnimation("corsairMoveR");
		ShadowRenderer->ChangeFrameAnimation("corsairMoveR");
	}



}
