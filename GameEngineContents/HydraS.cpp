
#include "PreCompile.h"
#include "HydraS.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Plaegue.h"
#include "HydraSUI.h"
#include "MiniMapPlayer.h"
#include"DroneBullet.h"


HydraS::HydraS()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(300.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, AuraRenderer(nullptr)
	, MainUI(nullptr)
{
}

HydraS::~HydraS()
{
}


void HydraS::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("hidraMove12");
	ShadowRenderer->ChangeFrameAnimation("hidraMove12");
}


void HydraS::Start()
{

	SoundPlayer = GameEngineSound::SoundPlayControl("HydraSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.5f);


	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });

		Renderer->CreateFrameAnimationFolder("hidraAttack0", FrameAnimation_DESC("hidraAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack1", FrameAnimation_DESC("hidraAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack2", FrameAnimation_DESC("hidraAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack3", FrameAnimation_DESC("hidraAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack4", FrameAnimation_DESC("hidraAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack5", FrameAnimation_DESC("hidraAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack6", FrameAnimation_DESC("hidraAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack7", FrameAnimation_DESC("hidraAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack8", FrameAnimation_DESC("hidraAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack9", FrameAnimation_DESC("hidraAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack10", FrameAnimation_DESC("hidraAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack11", FrameAnimation_DESC("hidraAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack12", FrameAnimation_DESC("hidraAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack13", FrameAnimation_DESC("hidraAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack14", FrameAnimation_DESC("hidraAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("hidraAttack15", FrameAnimation_DESC("hidraAttack15", 0.1f));

		Renderer->CreateFrameAnimationFolder("hidraMove12", FrameAnimation_DESC("hidraMove12", 0.1f));

		Renderer->ChangeFrameAnimation("hidraMove12");


		Renderer->AnimationBindEnd("hidraAttack0", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack1", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack2", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack3", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack4", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack5", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack6", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack7", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack8", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack9", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack10", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack11", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack12", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack13", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack14", &HydraS::AttEnd, this);
		Renderer->AnimationBindEnd("hidraAttack15", &HydraS::AttEnd, this);

	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		ShadowRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });

		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack0", FrameAnimation_DESC("hidraAttack0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack1", FrameAnimation_DESC("hidraAttack1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack2", FrameAnimation_DESC("hidraAttack2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack3", FrameAnimation_DESC("hidraAttack3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack4", FrameAnimation_DESC("hidraAttack4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack5", FrameAnimation_DESC("hidraAttack5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack6", FrameAnimation_DESC("hidraAttack6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack7", FrameAnimation_DESC("hidraAttack7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack8", FrameAnimation_DESC("hidraAttack8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack9", FrameAnimation_DESC("hidraAttack9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack10", FrameAnimation_DESC("hidraAttack10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack11", FrameAnimation_DESC("hidraAttack11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack12", FrameAnimation_DESC("hidraAttack12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack13", FrameAnimation_DESC("hidraAttack13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack14", FrameAnimation_DESC("hidraAttack14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("hidraAttack15", FrameAnimation_DESC("hidraAttack15", 0.1f));

		ShadowRenderer->CreateFrameAnimationFolder("hidraMove12", FrameAnimation_DESC("hidraMove12", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("hidraMove12");


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

		AuraRenderer = CreateComponent<GameEngineTextureRenderer>();
		AuraRenderer->CreateFrameAnimationFolder("Maelstorm", FrameAnimation_DESC("Maelstorm", 0.1f));
		AuraRenderer->ChangeFrameAnimation("Maelstorm");
		AuraRenderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		AuraRenderer->GetPixelData().MulColor.a = 1.f;
		AuraRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-1.f });



	}
 
	MainUI = GetLevel()->CreateActor<HydraSUI>(OBJECTORDER::UI);

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
		AttRenderer->GetTransform().SetLocalScale({ 600.f,600.f,1.f });

	}

	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);


	AttRenderer->Off();
	ClickRenderer->Off();
	MainUI->Off();


}

void HydraS::Update(float _DeltaTime)
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

				if (AttType)
				{
					TestUni = GetLevel()->CreateActor<Plaegue>(OBJECTORDER::Bullet);
					TestUni->GetTransform().SetWorldPosition(TarGetPos);
					AttType = !AttType;
				}
				else
				{
					TestUni2 = GetLevel()->CreateActor<DroneBullet>(OBJECTORDER::Bullet);
					TestUni2->GetTransform().SetWorldPosition(MyPos);
					TestUni2->SetTarGet(TarGet);
					AttType = !AttType;
					

				}
				



				



			}


			break;
		}

		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("hidraMove12");
			ShadowRenderer->ChangeFrameAnimation("hidraMove12");
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void HydraS::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack0");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack1");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack2");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack3");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack4");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack5");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack6");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack7");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack7");

	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack8");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack9");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack10");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack11");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack11");

	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("hidraAttack12");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack13");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack14");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("hidraAttack15");
		ShadowRenderer->ChangeFrameAnimation("hidraAttack15");
	}


}
