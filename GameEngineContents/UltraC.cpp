

#include "PreCompile.h"
#include "UltraC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include "UltraCUI.h"
#include "MiniMapPlayer.h"


UltraC::UltraC()
	: Speed(50.0f)
	, Renderer(nullptr)
	, BiconRenderer(nullptr)
	, Reach(200.f)
	, AttCheck(false)
	, AttTimeMax(0.8f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, AttCount(0)
	, AttCountMax(5)
	, m_Dir({ 0 })
	, BAniChange(false)
	,MainUI(nullptr)
{
}

UltraC::~UltraC()
{
}


void UltraC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("ultraStand");
}

void UltraC::Start()
{

	SoundPlayer = GameEngineSound::SoundPlayControl("UltraSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.5f);




	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });


		Renderer->CreateFrameAnimationFolder("ultraAttack0", FrameAnimation_DESC("ultraAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack1", FrameAnimation_DESC("ultraAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack2", FrameAnimation_DESC("ultraAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack3", FrameAnimation_DESC("ultraAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack4", FrameAnimation_DESC("ultraAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack5", FrameAnimation_DESC("ultraAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack6", FrameAnimation_DESC("ultraAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack7", FrameAnimation_DESC("ultraAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack8", FrameAnimation_DESC("ultraAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack9", FrameAnimation_DESC("ultraAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack10", FrameAnimation_DESC("ultraAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack11", FrameAnimation_DESC("ultraAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack12", FrameAnimation_DESC("ultraAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack13", FrameAnimation_DESC("ultraAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack14", FrameAnimation_DESC("ultraAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("ultraAttack15", FrameAnimation_DESC("ultraAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("ultraStand", FrameAnimation_DESC("ultraStand", 0.1f));

		Renderer->ChangeFrameAnimation("ultraStand");


		Renderer->AnimationBindEnd("ultraAttack0", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack1", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack2", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack3", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack4", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack5", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack6", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack7", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack8", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack9", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack10", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack11", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack12", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack13", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack14", &UltraC::AttEnd, this);
		Renderer->AnimationBindEnd("ultraAttack15", &UltraC::AttEnd, this);

	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });


		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack0", FrameAnimation_DESC("ultraAttack0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack1", FrameAnimation_DESC("ultraAttack1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack2", FrameAnimation_DESC("ultraAttack2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack3", FrameAnimation_DESC("ultraAttack3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack4", FrameAnimation_DESC("ultraAttack4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack5", FrameAnimation_DESC("ultraAttack5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack6", FrameAnimation_DESC("ultraAttack6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack7", FrameAnimation_DESC("ultraAttack7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack8", FrameAnimation_DESC("ultraAttack8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack9", FrameAnimation_DESC("ultraAttack9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack10", FrameAnimation_DESC("ultraAttack10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack11", FrameAnimation_DESC("ultraAttack11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack12", FrameAnimation_DESC("ultraAttack12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack13", FrameAnimation_DESC("ultraAttack13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack14", FrameAnimation_DESC("ultraAttack14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ultraAttack15", FrameAnimation_DESC("ultraAttack15", 0.1f));

		ShadowRenderer->CreateFrameAnimationFolder("ultraStand", FrameAnimation_DESC("ultraStand", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("ultraStand");

		ShadowRenderer->GetPixelData().MulColor.r = 0.f;
		ShadowRenderer->GetPixelData().MulColor.g = 0.f;
		ShadowRenderer->GetPixelData().MulColor.b = 0.f;
		ShadowRenderer->GetPixelData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 5.f;
		SLocalPos.x -= 5.f;
		SLocalPos.z += 0.5f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);
	

	}


	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->SetTexture("beacon.png");
		BiconRenderer->ScaleToTexture();
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	}

	MainUI = GetLevel()->CreateActor<UltraCUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
		//Collision->Off();
	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select4.png");
		ClickRenderer->ScaleToTexture();
		ClickRenderer->GetTransform().SetLocalPosition({ 0.f,-5.f,1.f });
	}

	{
		AttRenderer = CreateComponent<GameEngineTextureRenderer>();
		AttRenderer->SetTexture("SelectAtt.png");
		AttRenderer->GetTransform().SetLocalScale({ 400.f,400.f,1.f });

	}

	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);



	AttRenderer->Off();
	ClickRenderer->Off();
	MainUI->Off();



}

void UltraC::Update(float _DeltaTime)
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

	int Monsize = (int)Group.size();
	int MonCount = 0;
	AttCount = 0;
	AttCountMax = 3;

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

				SoundPlayer = GameEngineSound::SoundPlayControl("UlAtt2S.wav", false);
				SoundPlayer.PlaySpeed(1.f);
				SoundPlayer.Volume(0.2f);

				((UnitBase*)TarGet)->m_Info.m_Hp -= 70 + UnitBase::BZergUpgrade * 10;
			}
			break;
		}


		if (MonCount >= Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("ultraStand");
			AttTime = 0.f;
		}


	}



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}


void UltraC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("ultraAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("ultraAttack15");
	}


}
