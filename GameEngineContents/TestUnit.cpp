
#include "PreCompile.h"
#include "TestUnit.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DraBall.h"
#include "DragoonCUI.h"
#include "MiniMapPlayer.h"


TestUnit::TestUnit()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(150.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.8f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, MainUI(0)
{
}

TestUnit::~TestUnit()
{
}


void TestUnit::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("DragonStand");
	ShadowRenderer->ChangeFrameAnimation("DragonStand");

}

void TestUnit::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });
		

		Renderer->CreateFrameAnimationFolder("DragonStand", FrameAnimation_DESC("DragonStand0", 0.1f));
		Renderer->CreateFrameAnimationFolder("DragonAttack15", FrameAnimation_DESC("DragonAttack15", 0.1f));

		Renderer->ChangeFrameAnimation("DragonStand");

		Renderer->AnimationBindEnd("DragonAttack15", &TestUnit::AttEnd, this);

	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 96.f,96.f,1.f });


		ShadowRenderer->CreateFrameAnimationFolder("DragonStand", FrameAnimation_DESC("DragonStand0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("DragonAttack15", FrameAnimation_DESC("DragonAttack15", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("DragonStand");

		ShadowRenderer->AnimationBindEnd("DragonAttack15", &TestUnit::AttEnd, this);

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




	MainUI = GetLevel()->CreateActor<DragoonCUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
		//Collision->Off();
	}



	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select3.png");
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

void TestUnit::Update(float _DeltaTime)
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
		float MonLen  = Dist.Length();
		
		++MonCount;

		if (MonLen <= Reach)
		{
			Renderer->ChangeFrameAnimation("DragonAttack15");
			ShadowRenderer->ChangeFrameAnimation("DragonAttack15");
			if (AttCheck)
			{
				AttCheck = false;
			
				TestUni = GetLevel()->CreateActor<DraBall>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);
				TestUni->m_Info.Dammage = TestUni->m_Info.Dammage + UnitBase::CProUpgrade;
				
			

			}
			//BloodBullet
			//Spore

			break;
		
		}
		
		
		if (MonCount == Monsize)
		{
			Renderer->ChangeFrameAnimation("DragonStand");
			ShadowRenderer->ChangeFrameAnimation("DragonStand");
			AttTime =0.f;
		}


	}

	

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}

