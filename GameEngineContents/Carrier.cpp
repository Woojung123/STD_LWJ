
#include "PreCompile.h"
#include "Carrier.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"mutalBullet.h"
#include "CarrierAUI.h"
#include "MiniMapPlayer.h"

Carrier::Carrier()
	: Speed(50.0f)
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
	, AuraRenderer(nullptr)
	, BiconRenderer(nullptr)
	, MainUI(nullptr)
{
}

Carrier::~Carrier()
{
}


void Carrier::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	//Renderer->ChangeFrameAnimation("GardianMove12");
	BAniChange = false;
}



void Carrier::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });
		GetTransform().SetWorldPosition({ -990.f,310.f,0.f });


		Renderer->CreateFrameAnimationFolder("CarrierMove0", FrameAnimation_DESC("CarrierMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove1", FrameAnimation_DESC("CarrierMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove2", FrameAnimation_DESC("CarrierMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove3", FrameAnimation_DESC("CarrierMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove4", FrameAnimation_DESC("CarrierMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove5", FrameAnimation_DESC("CarrierMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove6", FrameAnimation_DESC("CarrierMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove7", FrameAnimation_DESC("CarrierMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove8", FrameAnimation_DESC("CarrierMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove9", FrameAnimation_DESC("CarrierMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove10", FrameAnimation_DESC("CarrierMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove11", FrameAnimation_DESC("CarrierMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove12", FrameAnimation_DESC("CarrierMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove13", FrameAnimation_DESC("CarrierMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove14", FrameAnimation_DESC("CarrierMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("CarrierMove15", FrameAnimation_DESC("CarrierMove15", 0.1f));


		Renderer->ChangeFrameAnimation("CarrierMove12");


		Renderer->AnimationBindEnd("CarrierMove0", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove1", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove2", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove3", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove4", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove5", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove6", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove7", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove8", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove9", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove10", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove11", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove12", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove13", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove14", &Carrier::AttEnd, this);
		Renderer->AnimationBindEnd("CarrierMove15", &Carrier::AttEnd, this);



	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });
		GetTransform().SetWorldPosition({ -990.f,310.f,0.f });


		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove0", FrameAnimation_DESC("CarrierMove0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove1", FrameAnimation_DESC("CarrierMove1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove2", FrameAnimation_DESC("CarrierMove2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove3", FrameAnimation_DESC("CarrierMove3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove4", FrameAnimation_DESC("CarrierMove4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove5", FrameAnimation_DESC("CarrierMove5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove6", FrameAnimation_DESC("CarrierMove6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove7", FrameAnimation_DESC("CarrierMove7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove8", FrameAnimation_DESC("CarrierMove8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove9", FrameAnimation_DESC("CarrierMove9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove10", FrameAnimation_DESC("CarrierMove10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove11", FrameAnimation_DESC("CarrierMove11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove12", FrameAnimation_DESC("CarrierMove12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove13", FrameAnimation_DESC("CarrierMove13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove14", FrameAnimation_DESC("CarrierMove14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CarrierMove15", FrameAnimation_DESC("CarrierMove15", 0.1f));


		ShadowRenderer->ChangeFrameAnimation("CarrierMove12");


		ShadowRenderer->GetColorData().MulColor.r = 0.f;
		ShadowRenderer->GetColorData().MulColor.g = 0.f;
		ShadowRenderer->GetColorData().MulColor.b = 0.f;
		ShadowRenderer->GetColorData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 25.f;
		SLocalPos.z += 0.5f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);


	}



	{

		AuraRenderer = CreateComponent<GameEngineTextureRenderer>();
		AuraRenderer->CreateFrameAnimationFolder("aulora0", FrameAnimation_DESC("aulora0", 0.1f));
		AuraRenderer->ChangeFrameAnimation("aulora0");
		AuraRenderer->GetTransform().SetLocalScale({ 120.f,120.f,1.f });
		float4 RenderWorldPos = AuraRenderer->GetTransform().GetWorldPosition();

		AuraRenderer->GetTransform().SetWorldPosition(RenderWorldPos);


	}


	{
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->CreateFrameAnimationFolder("pool", FrameAnimation_DESC("pool", 0.1f));
		BiconRenderer->ChangeFrameAnimation("pool");
		BiconRenderer->GetTransform().SetLocalScale({ 96.f,128.f,1.f });
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });


	}

	MainUI = GetLevel()->CreateActor<CarrierAUI>(OBJECTORDER::UI);

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
		AttRenderer->GetTransform().SetLocalScale({ 500.f,500.f,1.f });

	}

	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);



	AttRenderer->Off();
	ClickRenderer->Off();
	MainUI->Off();


}

void Carrier::Update(float _DeltaTime)
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
		MainUI->Off();
		ClickRenderer->Off();
		AttRenderer->Off();
	}


	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)(Group.size());
	int MonCount = 0;
	AttCount = 0;
	AttCountMax = 5;
	auto	iter = Group.begin();
	auto	iterEnd = Group.end();
	GameEngineActor* TarGet = nullptr;
	GameEngineActor* TarGet2 = nullptr;
	GameEngineActor* TarGet3 = nullptr;
	GameEngineActor* TarGet4 = nullptr;
	for (; iter != iterEnd; ++iter)
	{
		TarGet = (*iter);

		float4 TarGetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();
		float4 Dist = MyPos - TarGetPos;
		float MonLen = Dist.Length();

		++MonCount;

		if (MonLen <= Reach)
		{
			++AttCount;

			if (AttCount == 1)
			{
				TarGet2 = TarGet;
			}
			else if (AttCount == 2)
			{
				TarGet3 = TarGet;
			}
			else if (AttCount == 3)
			{
				TarGet4 = TarGet;
			}

			if (!BAniChange)
			{
				m_Dir = (TarGetPos - MyPos);
				m_Dir.Normalize();

				ChangeAni(TarGetPos, MyPos);
				BAniChange = true;
			}


			if (AttCheck)
			{

				if (AttCount == 3)
				{/*
					TestUni = GetLevel()->CreateActor<mutalBullet>(OBJECTORDER::Bullet);
					TestUni->GetTransform().SetWorldPosition(MyPos);
					TestUni->SetTarGet(TarGet);
					TestUni->m_Info.Dammage = 120;

					TestUni->TarGet = TarGet2;
					TestUni->TarGet2 = TarGet3;
					TestUni->TarGet3 = TarGet4;*/
				}

			}

			if (AttCountMax >= (Monsize - 1))
			{
				AttCountMax = (Monsize - 1);
			}

			if (AttCount >= AttCountMax)
			{
				AttCheck = false;
				AttCount = 0;
				break;
			}


		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			//Renderer->ChangeFrameAnimation("GardianMove12");
			AttTime = 0.f;
			AttCount = 0;
			AttCountMax = 5;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void Carrier::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove0");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove1");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove2");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove3");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove4");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove5");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove6");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove7");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove8");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove9");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove10");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove11");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("CarrierMove12");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove13");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove14");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("CarrierMove15");
		ShadowRenderer->ChangeFrameAnimation("CarrierMove15");
	}


}
