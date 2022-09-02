

#include "PreCompile.h"
#include "CannonB.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DraBall.h"
#include "CannonUI.h"

#include "MiniMapPlayer.h"



CannonB::CannonB()
	: Speed(50.0f)
	, Renderer(nullptr)
	, BiconRenderer(nullptr)
	, Reach(200.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.8f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, AttCount(0)
	, AttCountMax(5)
{
}

CannonB::~CannonB()
{
}


void CannonB::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	ShadowRenderer->ChangeFrameAnimation("CannonStand");
	Renderer->ChangeFrameAnimation("CannonStand");
}

void CannonB::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,128.f,1.f });


		Renderer->CreateFrameAnimationFolder("CannonStand", FrameAnimation_DESC("CannonStand", 0.1f));
		Renderer->CreateFrameAnimationFolder("CannonAtt", FrameAnimation_DESC("CannonAtt", 0.1f));

		Renderer->ChangeFrameAnimation("CannonStand");

		Renderer->AnimationBindEnd("CannonAtt", &CannonB::AttEnd, this);

	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 64.f,128.f,1.f });


		ShadowRenderer->CreateFrameAnimationFolder("CannonStand", FrameAnimation_DESC("CannonStand", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("CannonAtt", FrameAnimation_DESC("CannonAtt", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("CannonStand");

		ShadowRenderer->AnimationBindEnd("CannonAtt", &CannonB::AttEnd, this);

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
		BiconRenderer = CreateComponent<GameEngineTextureRenderer>();
		BiconRenderer->SetTexture("beacon.png");
		BiconRenderer->ScaleToTexture();
		float4 RenderWorldPos = BiconRenderer->GetTransform().GetWorldPosition();
		BiconRenderer->GetTransform().SetWorldPosition({ RenderWorldPos.x - 5.f, RenderWorldPos.y - 5.f , 1.f });
	}
	
	MainUI = GetLevel()->CreateActor<CannonUI>(OBJECTORDER::UI);

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
		AttRenderer->GetTransform().SetLocalScale({ 400.f,400.f,1.f });

	}


	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);



}

void CannonB::Update(float _DeltaTime)
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
			++AttCount;
			Renderer->ChangeFrameAnimation("CannonAtt");
			ShadowRenderer->ChangeFrameAnimation("CannonAtt");
			
			if (AttCheck)
			{
				//AttCheck = false;

				TestUni = GetLevel()->CreateActor<DraBall>(OBJECTORDER::Bullet);
				MyPos.y = MyPos.y + 10.f;
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);
				TestUni->m_Info.Dammage = 40;
				


			}
			//BloodBullet
			//Spore
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
			Renderer->ChangeFrameAnimation("CannonStand");
			ShadowRenderer->ChangeFrameAnimation("CannonStand");
			AttTime = 0.f;
			AttCountMax = 3;
			AttCount = 0;
			AttCheck = false;
		}


	}



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}

