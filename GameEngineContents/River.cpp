
#include "PreCompile.h"
#include "River.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"RiverBullet.h"
#include "RiverAUI.h"
#include "MiniMapPlayer.h"

River::River()
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
	, AuraRenderer(nullptr)
	, BiconRenderer(nullptr)
	, MainUI(nullptr)
{
}

River::~River()
{
}

void River::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;

}


void River::Start()
{


	SoundPlayer = GameEngineSound::SoundPlayControl("RiverSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.5f);


	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 84.f,84.f,1.f });


		Renderer->CreateFrameAnimationFolder("RiverMove0", FrameAnimation_DESC("RiverMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove1", FrameAnimation_DESC("RiverMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove2", FrameAnimation_DESC("RiverMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove3", FrameAnimation_DESC("RiverMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove4", FrameAnimation_DESC("RiverMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove5", FrameAnimation_DESC("RiverMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove6", FrameAnimation_DESC("RiverMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove7", FrameAnimation_DESC("RiverMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove8", FrameAnimation_DESC("RiverMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove9", FrameAnimation_DESC("RiverMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove10", FrameAnimation_DESC("RiverMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove11", FrameAnimation_DESC("RiverMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove12", FrameAnimation_DESC("RiverMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove13", FrameAnimation_DESC("RiverMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove14", FrameAnimation_DESC("RiverMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("RiverMove15", FrameAnimation_DESC("RiverMove15", 0.1f));
	
		Renderer->ChangeFrameAnimation("RiverMove15");

		Renderer->AnimationBindEnd("RiverMove0", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove1", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove2", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove3", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove4", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove5", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove6", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove7", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove8", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove9", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove10", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove11", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove12", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove13", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove14", &River::AttEnd, this);
		Renderer->AnimationBindEnd("RiverMove15", &River::AttEnd, this);

	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 84.f,84.f,1.f });


		ShadowRenderer->CreateFrameAnimationFolder("RiverMove0", FrameAnimation_DESC("RiverMove0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove1", FrameAnimation_DESC("RiverMove1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove2", FrameAnimation_DESC("RiverMove2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove3", FrameAnimation_DESC("RiverMove3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove4", FrameAnimation_DESC("RiverMove4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove5", FrameAnimation_DESC("RiverMove5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove6", FrameAnimation_DESC("RiverMove6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove7", FrameAnimation_DESC("RiverMove7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove8", FrameAnimation_DESC("RiverMove8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove9", FrameAnimation_DESC("RiverMove9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove10", FrameAnimation_DESC("RiverMove10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove11", FrameAnimation_DESC("RiverMove11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove12", FrameAnimation_DESC("RiverMove12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove13", FrameAnimation_DESC("RiverMove13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove14", FrameAnimation_DESC("RiverMove14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("RiverMove15", FrameAnimation_DESC("RiverMove15", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("RiverMove15");

	
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

	
		MainUI = GetLevel()->CreateActor<RiverAUI>(OBJECTORDER::UI);

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

void River::Update(float _DeltaTime)
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

				TestUni = GetLevel()->CreateActor<RiverBullet>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);
				TestUni->m_Info.Dammage = TestUni->m_Info.Dammage + UnitBase::AProUpgrade;


			}


			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void River::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("RiverMove0");
		ShadowRenderer->ChangeFrameAnimation("RiverMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove1");
		ShadowRenderer->ChangeFrameAnimation("RiverMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("RiverMove2");
		ShadowRenderer->ChangeFrameAnimation("RiverMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove3");
		ShadowRenderer->ChangeFrameAnimation("RiverMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("RiverMove4");
		ShadowRenderer->ChangeFrameAnimation("RiverMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove5");
		ShadowRenderer->ChangeFrameAnimation("RiverMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("RiverMove6");
		ShadowRenderer->ChangeFrameAnimation("RiverMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove7");
		ShadowRenderer->ChangeFrameAnimation("RiverMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("RiverMove8");
		ShadowRenderer->ChangeFrameAnimation("RiverMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove9");
		ShadowRenderer->ChangeFrameAnimation("RiverMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("RiverMove10");
		ShadowRenderer->ChangeFrameAnimation("RiverMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove11");
		ShadowRenderer->ChangeFrameAnimation("RiverMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("RiverMove12");
		ShadowRenderer->ChangeFrameAnimation("RiverMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove13");
		ShadowRenderer->ChangeFrameAnimation("RiverMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("RiverMove14");
		ShadowRenderer->ChangeFrameAnimation("RiverMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("RiverMove15");
		ShadowRenderer->ChangeFrameAnimation("RiverMove15");
	}


}
