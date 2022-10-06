
#include "PreCompile.h"
#include "Intercept.h"
#include "UnitBase.h"
#include "Carrier.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"

#include"GameEngineBase/GameEngineRandom.h"

Intercept::Intercept()
	: Speed(300.0f)
	, Renderer(nullptr)
	, Reach(250.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, AttCount(0)
	, AttCountMax(3)
	, Mycarrier(nullptr)
	, TarGet(0)
{
}

Intercept::~Intercept()
{
}


void Intercept::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	//Renderer->ChangeFrameAnimation("GardianMove12");
	BAniChange = false;
}



void Intercept::Start()
{




	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 32.f,32.f,1.f });
		


		Renderer->CreateFrameAnimationFolder("interceptMove0", FrameAnimation_DESC("interceptMove0", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove1", FrameAnimation_DESC("interceptMove1", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove2", FrameAnimation_DESC("interceptMove2", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove3", FrameAnimation_DESC("interceptMove3", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove4", FrameAnimation_DESC("interceptMove4", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove5", FrameAnimation_DESC("interceptMove5", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove6", FrameAnimation_DESC("interceptMove6", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove7", FrameAnimation_DESC("interceptMove7", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove8", FrameAnimation_DESC("interceptMove8", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove9", FrameAnimation_DESC("interceptMove9", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove10", FrameAnimation_DESC("interceptMove10", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove11", FrameAnimation_DESC("interceptMove11", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove12", FrameAnimation_DESC("interceptMove12", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove13", FrameAnimation_DESC("interceptMove13", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove14", FrameAnimation_DESC("interceptMove14", 1.f));
		Renderer->CreateFrameAnimationFolder("interceptMove15", FrameAnimation_DESC("interceptMove15", 1.f));


		Renderer->ChangeFrameAnimation("interceptMove12");


		
	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 32.f,32.f,1.f });
		


		ShadowRenderer->CreateFrameAnimationFolder("interceptMove0", FrameAnimation_DESC("interceptMove0", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove1", FrameAnimation_DESC("interceptMove1", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove2", FrameAnimation_DESC("interceptMove2", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove3", FrameAnimation_DESC("interceptMove3", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove4", FrameAnimation_DESC("interceptMove4", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove5", FrameAnimation_DESC("interceptMove5", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove6", FrameAnimation_DESC("interceptMove6", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove7", FrameAnimation_DESC("interceptMove7", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove8", FrameAnimation_DESC("interceptMove8", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove9", FrameAnimation_DESC("interceptMove9", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove10", FrameAnimation_DESC("interceptMove10", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove11", FrameAnimation_DESC("interceptMove11", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove12", FrameAnimation_DESC("interceptMove12", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove13", FrameAnimation_DESC("interceptMove13", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove14", FrameAnimation_DESC("interceptMove14", 1.f));
		ShadowRenderer->CreateFrameAnimationFolder("interceptMove15", FrameAnimation_DESC("interceptMove15", 1.f));

		ShadowRenderer->ChangeFrameAnimation("interceptMove12");


		ShadowRenderer->GetPixelData().MulColor.r = 0.f;
		ShadowRenderer->GetPixelData().MulColor.g = 0.f;
		ShadowRenderer->GetPixelData().MulColor.b = 0.f;
		ShadowRenderer->GetPixelData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 25.f;
		SLocalPos.z += 0.5f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);


	}








}

void Intercept::Update(float _DeltaTime)
{








	if (Mycarrier->interAtt)
	{

		if (TarGet != nullptr)
		{
			if (soundcheck)
			{	
				ShootPlayer = GameEngineSound::SoundPlayControl("InterShoot.wav", false);
				ShootPlayer.PlaySpeed(1.f);
				ShootPlayer.Volume(0.1f);
				soundcheck = false;
			}

			AttCheck = true;
			AttTime += _DeltaTime;

			if (AttTime >= 1.f)
			{
				AttTime -= 1.f;

				m_Info.Dammage = 30;
			

				((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage + UnitBase::AProUpgrade * 5;

			}


			float4 WorldPos = GetTransform().GetWorldPosition();
			float4 TargetPoint = TarGet->GetTransform().GetWorldPosition();


			if (MVcheck)
			{
				float RandomX = GameEngineRandom::MainRandom.RandomFloat(0, 300);
				float RandomY = GameEngineRandom::MainRandom.RandomFloat(0, 300);


				GoPoint.x = (TargetPoint.x - 150.f) + RandomX;
				GoPoint.y = (TargetPoint.y - 150.f) + RandomY;
				GoPoint.z = -30.f;

				m_Dir = (GoPoint - WorldPos);
				m_Dir.Normalize();

				MVcheck = false;
			}


			GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);


			ChangeAni(GoPoint, WorldPos);


			if ((int)(WorldPos.x + 5) > (int)(GoPoint.x) &&
				(int)(WorldPos.x - 5) < (int)(GoPoint.x)
				&& (int)(WorldPos.y - 5) < (int)(GoPoint.y)
				&& (int)(WorldPos.y + 5) > (int)(GoPoint.y))
			{
				MVcheck = true;

				//ShootPlayer = GameEngineSound::SoundPlayControl("InterShoot.wav", false);
				//ShootPlayer.PlaySpeed(1.f);
				//ShootPlayer.Volume(0.5f);
			}


			float4 WorldPos2 = GetTransform().GetWorldPosition();
			GetTransform().SetWorldPosition({ WorldPos2.x , WorldPos2.y , -30.f, WorldPos2.w });
		}
	}
	else
	{
		MVcheck = true;

		AttTime = 0.f;

		float4 WorldPos = GetTransform().GetWorldPosition();
		float4 TargetPoint = Mycarrier->GetTransform().GetWorldPosition();


		if (AttCheck)
		{
			
			m_Dir = (TargetPoint - WorldPos);
			m_Dir.Normalize();

			GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);


			ChangeAni(TargetPoint, WorldPos);

		}
		


		if ((int)(WorldPos.x + 10) > (int)(TargetPoint.x) &&
			(int)(WorldPos.x - 10) < (int)(TargetPoint.x)
			&& (int)(WorldPos.y - 10) < (int)(TargetPoint.y)
			&& (int)(WorldPos.y + 10) > (int)(TargetPoint.y))
		{
			
			AttCheck = false;
			soundcheck = true;

			float4 WorldPos2 = GetTransform().GetWorldPosition();
			GetTransform().SetWorldPosition({ WorldPos2.x , WorldPos2.y , -18.f, WorldPos2.w });
		}


	

		

	}

		

}

void Intercept::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("interceptMove0");
		ShadowRenderer->ChangeFrameAnimation("interceptMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove1");
		ShadowRenderer->ChangeFrameAnimation("interceptMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("interceptMove2");
		ShadowRenderer->ChangeFrameAnimation("interceptMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove3");
		ShadowRenderer->ChangeFrameAnimation("interceptMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("interceptMove4");
		ShadowRenderer->ChangeFrameAnimation("interceptMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove5");
		ShadowRenderer->ChangeFrameAnimation("interceptMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("interceptMove6");
		ShadowRenderer->ChangeFrameAnimation("interceptMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove7");
		ShadowRenderer->ChangeFrameAnimation("interceptMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("interceptMove8");
		ShadowRenderer->ChangeFrameAnimation("interceptMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove9");
		ShadowRenderer->ChangeFrameAnimation("interceptMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("interceptMove10");
		ShadowRenderer->ChangeFrameAnimation("interceptMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove11");
		ShadowRenderer->ChangeFrameAnimation("interceptMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("interceptMove12");
		ShadowRenderer->ChangeFrameAnimation("interceptMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove13");
		ShadowRenderer->ChangeFrameAnimation("interceptMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("interceptMove14");
		ShadowRenderer->ChangeFrameAnimation("interceptMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("interceptMove15");
		ShadowRenderer->ChangeFrameAnimation("interceptMove15");
	}


}
