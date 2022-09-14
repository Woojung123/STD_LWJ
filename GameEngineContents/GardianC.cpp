

#include "PreCompile.h"
#include "GardianC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"Spore.h"
#include "GardianAUI.h"
#include "MiniMapPlayer.h"

GardianC::GardianC()
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
	,AuraRenderer(nullptr)
	,BiconRenderer(nullptr)
	,MainUI(nullptr)
{
}

GardianC::~GardianC()
{
}


void GardianC::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	BAniChange = false;
}



void GardianC::Start()
{


	SoundPlayer = GameEngineSound::SoundPlayControl("GurdianSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.1f);


	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });
		GetTransform().SetWorldPosition({ -990.f,310.f,0.f });


		Renderer->CreateFrameAnimationFolder("GardianMove0", FrameAnimation_DESC("GardianMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove1", FrameAnimation_DESC("GardianMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove2", FrameAnimation_DESC("GardianMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove3", FrameAnimation_DESC("GardianMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove4", FrameAnimation_DESC("GardianMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove5", FrameAnimation_DESC("GardianMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove6", FrameAnimation_DESC("GardianMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove7", FrameAnimation_DESC("GardianMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove8", FrameAnimation_DESC("GardianMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove9", FrameAnimation_DESC("GardianMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove10", FrameAnimation_DESC("GardianMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove11", FrameAnimation_DESC("GardianMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove12", FrameAnimation_DESC("GardianMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove13", FrameAnimation_DESC("GardianMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove14", FrameAnimation_DESC("GardianMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("GardianMove15", FrameAnimation_DESC("GardianMove15", 0.1f));


		Renderer->ChangeFrameAnimation("GardianMove12");


		Renderer->AnimationBindEnd("GardianMove0", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove1", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove2", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove3", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove4", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove5", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove6", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove7", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove8", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove9", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove10", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove11", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove12", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove13", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove14", &GardianC::AttEnd, this);
		Renderer->AnimationBindEnd("GardianMove15", &GardianC::AttEnd, this);



	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });
		GetTransform().SetWorldPosition({ -990.f,310.f,0.f });


		ShadowRenderer->CreateFrameAnimationFolder("GardianMove0", FrameAnimation_DESC("GardianMove0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove1", FrameAnimation_DESC("GardianMove1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove2", FrameAnimation_DESC("GardianMove2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove3", FrameAnimation_DESC("GardianMove3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove4", FrameAnimation_DESC("GardianMove4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove5", FrameAnimation_DESC("GardianMove5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove6", FrameAnimation_DESC("GardianMove6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove7", FrameAnimation_DESC("GardianMove7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove8", FrameAnimation_DESC("GardianMove8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove9", FrameAnimation_DESC("GardianMove9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove10", FrameAnimation_DESC("GardianMove10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove11", FrameAnimation_DESC("GardianMove11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove12", FrameAnimation_DESC("GardianMove12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove13", FrameAnimation_DESC("GardianMove13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove14", FrameAnimation_DESC("GardianMove14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GardianMove15", FrameAnimation_DESC("GardianMove15", 0.1f));


		ShadowRenderer->ChangeFrameAnimation("GardianMove12");


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

	MainUI = GetLevel()->CreateActor<GardianAUI>(OBJECTORDER::UI);

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

void GardianC::Update(float _DeltaTime)
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
	AttCount = 0;
	AttCountMax = 5;
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
			++AttCount;
			if (!BAniChange)
			{
				m_Dir = (TarGetPos - MyPos);
				m_Dir.Normalize();

				ChangeAni(TarGetPos, MyPos);
				BAniChange = true;
			}


			if (AttCheck)
			{
				
				
				TestUni = GetLevel()->CreateActor<Spore>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);
				TestUni->m_Info.Dammage = 80;
				TestUni->m_Info.Dammage = TestUni->m_Info.Dammage + UnitBase::AZergUpgrade;
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

void GardianC::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("GardianMove0");
		ShadowRenderer->ChangeFrameAnimation("GardianMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove1");
		ShadowRenderer->ChangeFrameAnimation("GardianMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("GardianMove2");
		ShadowRenderer->ChangeFrameAnimation("GardianMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove3");
		ShadowRenderer->ChangeFrameAnimation("GardianMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("GardianMove4");
		ShadowRenderer->ChangeFrameAnimation("GardianMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove5");
		ShadowRenderer->ChangeFrameAnimation("GardianMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("GardianMove6");
		ShadowRenderer->ChangeFrameAnimation("GardianMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove7");
		ShadowRenderer->ChangeFrameAnimation("GardianMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("GardianMove8");
		ShadowRenderer->ChangeFrameAnimation("GardianMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove9");
		ShadowRenderer->ChangeFrameAnimation("GardianMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("GardianMove10");
		ShadowRenderer->ChangeFrameAnimation("GardianMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove11");
		ShadowRenderer->ChangeFrameAnimation("GardianMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("GardianMove12");
		ShadowRenderer->ChangeFrameAnimation("GardianMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove13");
		ShadowRenderer->ChangeFrameAnimation("GardianMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("GardianMove14");
		ShadowRenderer->ChangeFrameAnimation("GardianMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("GardianMove15");
		ShadowRenderer->ChangeFrameAnimation("GardianMove15");
	}


}
