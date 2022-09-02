

#include "PreCompile.h"
#include "GhostS.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"SGbullet.h"
#include "GhostSUI.h"
#include "MiniMapPlayer.h"


GhostS::GhostS()
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
	, BulletType(0)
	,AuraRenderer(nullptr)
	,MainUI(nullptr)

{
}

GhostS::~GhostS()
{
}

void GhostS::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("ChostStand");
	ShadowRenderer->ChangeFrameAnimation("ChostStand");

}


void GhostS::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });

		Renderer->CreateFrameAnimationFolder("GhostAttack0", FrameAnimation_DESC("GhostAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack1", FrameAnimation_DESC("GhostAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack2", FrameAnimation_DESC("GhostAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack3", FrameAnimation_DESC("GhostAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack4", FrameAnimation_DESC("GhostAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack5", FrameAnimation_DESC("GhostAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack6", FrameAnimation_DESC("GhostAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack7", FrameAnimation_DESC("GhostAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack8", FrameAnimation_DESC("GhostAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack9", FrameAnimation_DESC("GhostAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack10", FrameAnimation_DESC("GhostAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack11", FrameAnimation_DESC("GhostAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack12", FrameAnimation_DESC("GhostAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack13", FrameAnimation_DESC("GhostAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack14", FrameAnimation_DESC("GhostAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("GhostAttack15", FrameAnimation_DESC("GhostAttack15", 0.1f));
		Renderer->CreateFrameAnimationFolder("ChostStand", FrameAnimation_DESC("ChostStand", 0.1f));


		Renderer->ChangeFrameAnimation("ChostStand");

		Renderer->AnimationBindEnd("GhostAttack0", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack1", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack2", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack3", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack4", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack5", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack6", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack7", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack8", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack9", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack10", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack11", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack12", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack13", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack14", &GhostS::AttEnd, this);
		Renderer->AnimationBindEnd("GhostAttack15", &GhostS::AttEnd, this);




	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		ShadowRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });

		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack0", FrameAnimation_DESC("GhostAttack0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack1", FrameAnimation_DESC("GhostAttack1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack2", FrameAnimation_DESC("GhostAttack2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack3", FrameAnimation_DESC("GhostAttack3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack4", FrameAnimation_DESC("GhostAttack4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack5", FrameAnimation_DESC("GhostAttack5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack6", FrameAnimation_DESC("GhostAttack6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack7", FrameAnimation_DESC("GhostAttack7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack8", FrameAnimation_DESC("GhostAttack8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack9", FrameAnimation_DESC("GhostAttack9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack10", FrameAnimation_DESC("GhostAttack10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack11", FrameAnimation_DESC("GhostAttack11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack12", FrameAnimation_DESC("GhostAttack12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack13", FrameAnimation_DESC("GhostAttack13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack14", FrameAnimation_DESC("GhostAttack14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("GhostAttack15", FrameAnimation_DESC("GhostAttack15", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ChostStand", FrameAnimation_DESC("ChostStand", 0.1f));


		ShadowRenderer->ChangeFrameAnimation("ChostStand");

		ShadowRenderer->GetColorData().MulColor.r = 0.f;
		ShadowRenderer->GetColorData().MulColor.g = 0.f;
		ShadowRenderer->GetColorData().MulColor.b = 0.f;
		ShadowRenderer->GetColorData().MulColor.a = 0.5f;


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
		AuraRenderer->GetColorData().MulColor.a = 1.f;
		AuraRenderer->GetTransform().SetLocalPosition({0.f,0.f,-1.f});

	}

 

	MainUI = GetLevel()->CreateActor<GhostSUI>(OBJECTORDER::UI);

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



}

void GhostS::Update(float _DeltaTime)
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

				if (BulletType == 0)
				{
					TestUni = GetLevel()->CreateActor<SGbullet>(OBJECTORDER::Bullet);
					TestUni->GetTransform().SetWorldPosition(MyPos);
					TestUni->SetTarGet(TarGet);
					TestUni->EffType = BulletType;
					++BulletType;
					break;
				}
				else if (BulletType == 1)
				{
					TestUni = GetLevel()->CreateActor<SGbullet>(OBJECTORDER::Bullet);
					TestUni->GetTransform().SetWorldPosition(MyPos);
					TestUni->SetTarGet(TarGet);
					TestUni->EffType = BulletType;
					++BulletType;
					break;
				}
				else if (BulletType == 2)
				{
					TestUni = GetLevel()->CreateActor<SGbullet>(OBJECTORDER::Bullet);
					TestUni->GetTransform().SetWorldPosition(MyPos);
					TestUni->SetTarGet(TarGet);
					TestUni->EffType = BulletType;
					BulletType = 0;
					break;
				}


				



			}


			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("ChostStand");
			ShadowRenderer->ChangeFrameAnimation("ChostStand");
			AttTime = 0.f;
			BulletType = 0;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void GhostS::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack0");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack1");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack2");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack3");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack4");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack5");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack6");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack6");

	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack7");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack8");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack9");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack10");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack11");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("GhostAttack12");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack13");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack14");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("GhostAttack15");
		ShadowRenderer->ChangeFrameAnimation("GhostAttack15");
	}


}
