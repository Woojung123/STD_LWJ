#include "PreCompile.h"
#include "MarinC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"TerranBaseBullet.h"
#include "MarinCUI.h"
#include "MiniMapPlayer.h"


MarinC::MarinC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.8f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, MainUI(nullptr)
{
}

MarinC::~MarinC()
{
}

void MarinC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("MarrineStand");
	ShadowRenderer->ChangeFrameAnimation("MarrineStand");
}



void MarinC::Start()
{



	SoundPlayer = GameEngineSound::SoundPlayControl("MarinSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.5f);


	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 50.f,50.f,1.f });
		


		Renderer->CreateFrameAnimationFolder("MarineAttack0", FrameAnimation_DESC("MarineAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack1", FrameAnimation_DESC("MarineAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack2", FrameAnimation_DESC("MarineAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack3", FrameAnimation_DESC("MarineAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack4", FrameAnimation_DESC("MarineAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack5", FrameAnimation_DESC("MarineAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack6", FrameAnimation_DESC("MarineAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack7", FrameAnimation_DESC("MarineAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack8", FrameAnimation_DESC("MarineAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack9", FrameAnimation_DESC("MarineAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack10", FrameAnimation_DESC("MarineAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack11", FrameAnimation_DESC("MarineAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack12", FrameAnimation_DESC("MarineAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack13", FrameAnimation_DESC("MarineAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack14", FrameAnimation_DESC("MarineAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarineAttack15", FrameAnimation_DESC("MarineAttack15", 0.1f));
		Renderer->CreateFrameAnimationFolder("MarrineStand", FrameAnimation_DESC("MarrineStand", 0.1f));


		Renderer->ChangeFrameAnimation("MarrineStand");


		Renderer->AnimationBindEnd("MarineAttack0", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack1", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack2", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack3", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack4", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack5", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack6", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack7", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack8", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack9", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack10", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack11", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack12", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack13", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack14", &MarinC::AttEnd, this);
		Renderer->AnimationBindEnd("MarineAttack15", &MarinC::AttEnd, this);


	}
	
	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 50.f,50.f,1.f });



		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack0", FrameAnimation_DESC("MarineAttack0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack1", FrameAnimation_DESC("MarineAttack1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack2", FrameAnimation_DESC("MarineAttack2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack3", FrameAnimation_DESC("MarineAttack3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack4", FrameAnimation_DESC("MarineAttack4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack5", FrameAnimation_DESC("MarineAttack5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack6", FrameAnimation_DESC("MarineAttack6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack7", FrameAnimation_DESC("MarineAttack7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack8", FrameAnimation_DESC("MarineAttack8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack9", FrameAnimation_DESC("MarineAttack9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack10", FrameAnimation_DESC("MarineAttack10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack11", FrameAnimation_DESC("MarineAttack11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack12", FrameAnimation_DESC("MarineAttack12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack13", FrameAnimation_DESC("MarineAttack13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack14", FrameAnimation_DESC("MarineAttack14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarineAttack15", FrameAnimation_DESC("MarineAttack15", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("MarrineStand", FrameAnimation_DESC("MarrineStand", 0.1f));


		ShadowRenderer->ChangeFrameAnimation("MarrineStand");


		ShadowRenderer->GetPixelData().MulColor.r = 0.f;
		ShadowRenderer->GetPixelData().MulColor.g = 0.f;
		ShadowRenderer->GetPixelData().MulColor.b = 0.f;
		ShadowRenderer->GetPixelData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 5.f;
		SLocalPos.x -= 5.f;
		SLocalPos.z += 1.f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);

	}



	MainUI = GetLevel()->CreateActor<MarinCUI>(OBJECTORDER::UI);

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

void MarinC::Update(float _DeltaTime)
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

				TestUni = GetLevel()->CreateActor<TerranBaseBullet>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(TarGetPos);
				TestUni->TarGet = TarGet;
				TestUni->m_Info.Dammage = TestUni->m_Info.Dammage + UnitBase::CTerUpgrade;

			}


			break;
		}


		if (MonCount >= Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("MarrineStand");
			ShadowRenderer->ChangeFrameAnimation("MarrineStand");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void MarinC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack0");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack0");

	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack1");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack1");

	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack2");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack2");

	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack3");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack4");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack5");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack6");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack7");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack8");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack9");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack10");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack11");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("MarineAttack12");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack13");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack14");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("MarineAttack15");
		ShadowRenderer->ChangeFrameAnimation("MarineAttack15");
	}


}
