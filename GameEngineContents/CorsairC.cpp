

#include "PreCompile.h"
#include "CorsairC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"CorSplash.h"
#include "CorsairCUI.h"

#include "MiniMapPlayer.h"

CorsairC::CorsairC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, MainUI(0)
{
}

CorsairC::~CorsairC()
{
}


void CorsairC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("corsairMoveD");
	ShadowRenderer->ChangeFrameAnimation("corsairMoveD");
}



void CorsairC::Start()
{

	SoundPlayer = GameEngineSound::SoundPlayControl("CorsairSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.1f);



	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });
		

		Renderer->CreateFrameAnimationFolder("corsairAttack0", FrameAnimation_DESC("corsairAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack1", FrameAnimation_DESC("corsairAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack2", FrameAnimation_DESC("corsairAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack3", FrameAnimation_DESC("corsairAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack4", FrameAnimation_DESC("corsairAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack5", FrameAnimation_DESC("corsairAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack6", FrameAnimation_DESC("corsairAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack7", FrameAnimation_DESC("corsairAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack8", FrameAnimation_DESC("corsairAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack9", FrameAnimation_DESC("corsairAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack10", FrameAnimation_DESC("corsairAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack11", FrameAnimation_DESC("corsairAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack12", FrameAnimation_DESC("corsairAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack13", FrameAnimation_DESC("corsairAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack14", FrameAnimation_DESC("corsairAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("corsairAttack15", FrameAnimation_DESC("corsairAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("corsairMoveD", FrameAnimation_DESC("corsairMoveD", 0.1f));

		Renderer->ChangeFrameAnimation("corsairMoveD");


		Renderer->AnimationBindEnd("corsairAttack0", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack1", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack2", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack3", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack4", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack5", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack6", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack7", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack8", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack9", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack10", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack11", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack12", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack13", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack14", &CorsairC::AttEnd, this);
		Renderer->AnimationBindEnd("corsairAttack15", &CorsairC::AttEnd, this);

	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });


		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack0", FrameAnimation_DESC("corsairAttack0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack1", FrameAnimation_DESC("corsairAttack1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack2", FrameAnimation_DESC("corsairAttack2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack3", FrameAnimation_DESC("corsairAttack3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack4", FrameAnimation_DESC("corsairAttack4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack5", FrameAnimation_DESC("corsairAttack5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack6", FrameAnimation_DESC("corsairAttack6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack7", FrameAnimation_DESC("corsairAttack7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack8", FrameAnimation_DESC("corsairAttack8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack9", FrameAnimation_DESC("corsairAttack9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack10", FrameAnimation_DESC("corsairAttack10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack11", FrameAnimation_DESC("corsairAttack11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack12", FrameAnimation_DESC("corsairAttack12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack13", FrameAnimation_DESC("corsairAttack13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack14", FrameAnimation_DESC("corsairAttack14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("corsairAttack15", FrameAnimation_DESC("corsairAttack15", 0.1f));

		ShadowRenderer->CreateFrameAnimationFolder("corsairMoveD", FrameAnimation_DESC("corsairMoveD", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("corsairMoveD");

		ShadowRenderer->GetPixelData().MulColor.r = 0.f;
		ShadowRenderer->GetPixelData().MulColor.g = 0.f;
		ShadowRenderer->GetPixelData().MulColor.b = 0.f;
		ShadowRenderer->GetPixelData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 25.f;
		SLocalPos.z += 1.f;
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

	{
		AttRenderer = CreateComponent<GameEngineTextureRenderer>();
		AttRenderer->SetTexture("SelectAtt.png");
		AttRenderer->GetTransform().SetLocalScale({ 300.f,300.f,1.f });

	}
	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);


	AttRenderer->Off();
	ClickRenderer->Off();
	MainUI->Off();



}

void CorsairC::Update(float _DeltaTime)
{

	MiniPlayUnit->UnitPos = GetTransform().GetWorldPosition();

	if (m_bClickCheck)
	{
		MainUI->On();
		ClickRenderer->On();
		AttRenderer->On();
	}
	else
	{

		if (m_bDragCheck)
		{
			MainUI->Off();
			ClickRenderer->On();
			AttRenderer->On();
		}
		else
		{
			MainUI->Off();
			ClickRenderer->Off();
			AttRenderer->Off();
		}
	}

	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)(Group.size());
	int MonCount = 0;

	auto	iter = Group.begin();
	auto	iterEnd = Group.end();

	for (; iter != iterEnd; ++iter)
	{
		GameEngineActor* TarGet = (*iter);
		float4 TarGetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();
		float4 Dist = MyPos - TarGetPos;
		float MonLen = Dist.Length();

		++MonCount;

		if (MonLen <= Reach)
		{

			if (!BAniChange)
			{
				m_Dir = (TarGetPos - MyPos);
				m_Dir.Normalize();

				ChangeAni(TarGetPos, MyPos);
				BAniChange = true;
			}

			if (AttCheck)
			{

				AttCheck = false;

				BAniChange = false;

				TestUni = GetLevel()->CreateActor<CorSplash>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->m_Info.Dammage = TestUni->m_Info.Dammage + UnitBase::CProUpgrade;

			}
			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("corsairMoveD");
			ShadowRenderer->ChangeFrameAnimation("corsairMoveD");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void CorsairC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack0");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack1");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack2");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack3");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack3");

	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack4");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack5");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack6");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack7");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack8");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack9");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack10");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack11");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("corsairAttack12");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack13");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack14");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("corsairAttack15");
		ShadowRenderer->ChangeFrameAnimation("corsairAttack15");
	}


}
