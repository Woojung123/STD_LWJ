
#include "PreCompile.h"
#include "Builder.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"CorSplash.h"
#include "CorsairCUI.h"
#include "MainMouse.h"


#include "BuildImage.h"



Builder::Builder()
	: Speed(0.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, Movecheck(false)
	, SpeedReset(false)
	, BuildCheck(false)
	, BuildPos({0})
	,m_DraC(0)
	,m_GhostC(0)
	,m_MarinC(0)
	,m_ZealotC(0)
	,m_HydraC(0)
	,m_CorsairC(0)
	,m_ZerglingC(0)
	,m_HighTB(0)
	,m_PhotoB(0)
	,m_UltraB(0)
	,m_ArbitorB(0)
	,m_DarkTB(0)
	,m_SunkenB(0)
	,m_MutalA(0)
	,m_GardianA(0)
	,m_CarrierA(0)
	,m_RiverA(0)
	,m_ArconA(0)
	,m_GhostS(0)
	,m_DroneS(0)
	,m_ProbeS(0)
	,m_HydraS(0)
	,GradeType(0)
	,BuildMake(false)
{
}

Builder::~Builder()
{
}


void Builder::Start()
{

	m_Type = UNITTYPE::Builder;
	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });


		Renderer->CreateFrameAnimationFolder("BcorsairMove0", FrameAnimation_DESC("BcorsairMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove1", FrameAnimation_DESC("BcorsairMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove2", FrameAnimation_DESC("BcorsairMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove3", FrameAnimation_DESC("BcorsairMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove4", FrameAnimation_DESC("BcorsairMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove5", FrameAnimation_DESC("BcorsairMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove6", FrameAnimation_DESC("BcorsairMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove7", FrameAnimation_DESC("BcorsairMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove8", FrameAnimation_DESC("BcorsairMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove9", FrameAnimation_DESC("BcorsairMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove10", FrameAnimation_DESC("BcorsairMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove11", FrameAnimation_DESC("BcorsairMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove12", FrameAnimation_DESC("BcorsairMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove13", FrameAnimation_DESC("BcorsairMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove14", FrameAnimation_DESC("BcorsairMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("BcorsairMove15", FrameAnimation_DESC("BcorsairMove15", 0.1f));

		
		Renderer->ChangeFrameAnimation("BcorsairMove12");


	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });


		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove0", FrameAnimation_DESC("BcorsairMove0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove1", FrameAnimation_DESC("BcorsairMove1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove2", FrameAnimation_DESC("BcorsairMove2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove3", FrameAnimation_DESC("BcorsairMove3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove4", FrameAnimation_DESC("BcorsairMove4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove5", FrameAnimation_DESC("BcorsairMove5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove6", FrameAnimation_DESC("BcorsairMove6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove7", FrameAnimation_DESC("BcorsairMove7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove8", FrameAnimation_DESC("BcorsairMove8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove9", FrameAnimation_DESC("BcorsairMove9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove10", FrameAnimation_DESC("BcorsairMove10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove11", FrameAnimation_DESC("BcorsairMove11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove12", FrameAnimation_DESC("BcorsairMove12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove13", FrameAnimation_DESC("BcorsairMove13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove14", FrameAnimation_DESC("BcorsairMove14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("BcorsairMove15", FrameAnimation_DESC("BcorsairMove15", 0.1f));


		ShadowRenderer->ChangeFrameAnimation("BcorsairMove12");

		ShadowRenderer->GetColorData().MulColor.r = 0.f;
		ShadowRenderer->GetColorData().MulColor.g = 0.f;
		ShadowRenderer->GetColorData().MulColor.b = 0.f;
		ShadowRenderer->GetColorData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 25.f;
		SLocalPos.z += 0.5f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);

	}


	MainUI = GetLevel()->CreateActor<CorsairCUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
		//Collision->Off();
	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select2.png");
		ClickRenderer->ScaleToTexture();
		ClickRenderer->GetTransform().SetLocalPosition({ 0.f,-5.f,1.f });
	}


	GameEngineInput::GetInst()->CreateKey("RClick", VK_RBUTTON);
	GameEngineInput::GetInst()->CreateKey("MakeClick", 'B');
	GameEngineInput::GetInst()->CreateKey("PlusClick", 'A');
}

void Builder::Update(float _DeltaTime)
{
	if (m_bClickCheck)
	{
		MainUI->On();
		ClickRenderer->On();
		MoveCheck(_DeltaTime);


		if (true == GameEngineInput::GetInst()->IsDown("MakeClick"))
		{
			m_MainMouse->BuildCheck = true;

		}


		if (true == GameEngineInput::GetInst()->IsDown("PlusClick"))
		{
			m_MainMouse->PlusCheck = true;

		}


	}
	else
	{
		MainUI->Off();
		ClickRenderer->Off();
	}

	


	if (BuildCheck)
	{

	
		MyPos = GetTransform().GetWorldPosition();


		m_Dir = (BuildPos - MyPos);
		m_Dir.Normalize();

		Movecheck = true;


		ChangeAni(BuildPos, MyPos);


		MyPos = GetTransform().GetWorldPosition();


		if (Speed == 0.f)
		{
			SpeedReset = true;
		}

		if (SpeedReset)
		{
			Speed += _DeltaTime * 200.f;

			if (Speed >= 300.f)
			{
				Speed = 300.f;
				SpeedReset = false;
			}

		}


		GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);


		if ((int)(MyPos.x + 300) > (int)(BuildPos.x) &&
			(int)(MyPos.x - 300) < (int)(BuildPos.x)
			&& (int)(MyPos.y -300) < (int)(BuildPos.y)
			&& (int)(MyPos.y + 300) > (int)(BuildPos.y))
		{



			if (BuildMake)
			{
				BuildMake = false;
				Speed = 0.f;
				BuildCheck = false;
				Movecheck = false;
				
				
				//扒拱积己
				BuildImage* TestUni = GetLevel()->CreateActor<BuildImage>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(BuildPos);
				TestUni->m_Bulder = this;
				m_bClickCheck = true;
				TestUni->Buildingtype = GradeType;
				

			}
			else
			{

				Speed = 0.f;
				BuildCheck = false;
				Movecheck = false;
				//扒拱积己
				BuildImage* TestUni = GetLevel()->CreateActor<BuildImage>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(BuildPos);
				TestUni->m_Bulder = this;
				m_bClickCheck = true;
			}
			


		}


	}
	else
	{

		if (Movecheck)
		{
			MyPos = GetTransform().GetWorldPosition();


			if (Speed == 0.f)
			{
				SpeedReset = true;
			}

			if (SpeedReset)
			{
				Speed += _DeltaTime * 200.f;

				if (Speed >= 300.f)
				{
					Speed = 300.f;
					SpeedReset = false;
				}

			}


			GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);


			if ((int)(MyPos.x + 10) > (int)(WorldPos.x) &&
				(int)(MyPos.x - 10) < (int)(WorldPos.x)
				&& (int)(MyPos.y - 10) < (int)(WorldPos.y)
				&& (int)(MyPos.y + 10) > (int)(WorldPos.y))
			{
				Speed = 0.f;
				Movecheck = false;
			}



		}


	}


	float4 WorldPos2 = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos2.x , WorldPos2.y , -25.f, WorldPos2.w });




}

void Builder::MoveCheck(float _DeltaTime)
{
	
	if (true == GameEngineInput::GetInst()->IsDown("RClick"))
	{
		
		WorldPos.x = GetLevel()->GetMainCamera()->GetMouseWorldPosition().x;
		WorldPos.y = GetLevel()->GetMainCamera()->GetMouseWorldPosition().y;
		WorldPos.z = -25.f;
		MyPos = GetTransform().GetWorldPosition();


		m_Dir = (WorldPos - MyPos);
		m_Dir.Normalize();

		Movecheck = true;
		
		
		ChangeAni(WorldPos, MyPos);


	}
}




void Builder::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove0");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove1");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove2");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove3");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove4");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove5");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove6");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove7");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove8");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove9");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove10");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove11");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("BcorsairMove12");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove13");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove14");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("BcorsairMove15");
		ShadowRenderer->ChangeFrameAnimation("BcorsairMove15");
	}


}
