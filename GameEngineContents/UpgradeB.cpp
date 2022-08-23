#include "PreCompile.h"
#include "UpgradeB.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DraBall.h"
#include "UpgradeBUI.h"




UpgradeB::UpgradeB()
	: Speed(50.0f)
	, Renderer(nullptr)
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

UpgradeB::~UpgradeB()
{
}


void UpgradeB::AttEnd(const FrameAnimation_DESC& _Info)
{

}

void UpgradeB::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 96.f,128.f,1.f });


		Renderer->CreateFrameAnimationFolder("chamber", FrameAnimation_DESC("chamber", 0.1f));
		
		Renderer->ChangeFrameAnimation("chamber");


	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 96.f,128.f,1.f });


		ShadowRenderer->CreateFrameAnimationFolder("chamber", FrameAnimation_DESC("chamber", 0.1f));

		ShadowRenderer->ChangeFrameAnimation("chamber");

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


	MainUI = GetLevel()->CreateActor<UpgradeBUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
		//Collision->Off();
	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select5.png");
		ClickRenderer->ScaleToTexture();
		ClickRenderer->GetTransform().SetLocalPosition({ 0.f,-5.f,1.f });
	}

	



}

void UpgradeB::Update(float _DeltaTime)
{
	if (m_bClickCheck)
	{
		MainUI->On();
		ClickRenderer->On();
		
	}
	else
	{
		MainUI->Off();
		ClickRenderer->Off();
		
	}



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}

