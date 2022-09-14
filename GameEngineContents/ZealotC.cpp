
#include "PreCompile.h"
#include "ZealotC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Sunken.h"
#include "ZealotCUI.h"
#include "MiniMapPlayer.h"


ZealotC::ZealotC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.5f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, MainUI(nullptr)
{
}

ZealotC::~ZealotC()
{
}

void ZealotC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("zelotStand12");
	ShadowRenderer->ChangeFrameAnimation("zelotStand12");
}


void ZealotC::Start()
{
	SoundPlayer = GameEngineSound::SoundPlayControl("ZealotSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.1f);



	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		


		Renderer->CreateFrameAnimationFolder("zelotAttack0", FrameAnimation_DESC("zelotAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack1", FrameAnimation_DESC("zelotAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack2", FrameAnimation_DESC("zelotAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack3", FrameAnimation_DESC("zelotAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack4", FrameAnimation_DESC("zelotAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack5", FrameAnimation_DESC("zelotAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack6", FrameAnimation_DESC("zelotAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack7", FrameAnimation_DESC("zelotAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack8", FrameAnimation_DESC("zelotAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack9", FrameAnimation_DESC("zelotAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack10", FrameAnimation_DESC("zelotAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack11", FrameAnimation_DESC("zelotAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack12", FrameAnimation_DESC("zelotAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack13", FrameAnimation_DESC("zelotAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack14", FrameAnimation_DESC("zelotAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("zelotAttack15", FrameAnimation_DESC("zelotAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("zelotStand12", FrameAnimation_DESC("zelotStand12", 0.1f));

		Renderer->ChangeFrameAnimation("zelotStand12");


		Renderer->AnimationBindEnd("zelotAttack0", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack1", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack2", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack3", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack4", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack5", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack6", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack7", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack8", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack9", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack10", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack11", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack12", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack13", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack14", &ZealotC::AttEnd, this);
		Renderer->AnimationBindEnd("zelotAttack15", &ZealotC::AttEnd, this);

	}

	
	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });



		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack0", FrameAnimation_DESC("zelotAttack0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack1", FrameAnimation_DESC("zelotAttack1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack2", FrameAnimation_DESC("zelotAttack2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack3", FrameAnimation_DESC("zelotAttack3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack4", FrameAnimation_DESC("zelotAttack4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack5", FrameAnimation_DESC("zelotAttack5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack6", FrameAnimation_DESC("zelotAttack6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack7", FrameAnimation_DESC("zelotAttack7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack8", FrameAnimation_DESC("zelotAttack8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack9", FrameAnimation_DESC("zelotAttack9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack10", FrameAnimation_DESC("zelotAttack10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack11", FrameAnimation_DESC("zelotAttack11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack12", FrameAnimation_DESC("zelotAttack12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack13", FrameAnimation_DESC("zelotAttack13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack14", FrameAnimation_DESC("zelotAttack14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("zelotAttack15", FrameAnimation_DESC("zelotAttack15", 0.1f));

		ShadowRenderer->CreateFrameAnimationFolder("zelotStand12", FrameAnimation_DESC("zelotStand12", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("zelotStand12");

		ShadowRenderer->GetColorData().MulColor.r = 0.f;
		ShadowRenderer->GetColorData().MulColor.g = 0.f;
		ShadowRenderer->GetColorData().MulColor.b = 0.f;
		ShadowRenderer->GetColorData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 5.f;
		SLocalPos.x -= 5.f;
		SLocalPos.z += 1.f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);
	}




	MainUI = GetLevel()->CreateActor<ZealotCUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
		//Collision->Off();
	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select1.png");
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

void ZealotC::Update(float _DeltaTime)
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
				TestUni = GetLevel()->CreateActor<Sunken>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->TarGet = TarGet;
				TestUni->m_Info.Dammage = TestUni->m_Info.Dammage + UnitBase::CProUpgrade;
			}


			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("zelotStand12");
			ShadowRenderer->ChangeFrameAnimation("zelotStand12");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void ZealotC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack0");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack1");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack2");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack3");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack4");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack5");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack6");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack7");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack8");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack9");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack10");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack11");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("zelotAttack12");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack13");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack14");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("zelotAttack15");
		ShadowRenderer->ChangeFrameAnimation("zelotAttack15");
	}


}
