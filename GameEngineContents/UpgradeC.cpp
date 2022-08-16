#include "PreCompile.h"
#include "UpgradeC.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DraBall.h"
#include "UpgradeCUI.h"




UpgradeC::UpgradeC()
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

UpgradeC::~UpgradeC()
{
}


void UpgradeC::AttEnd(const FrameAnimation_DESC& _Info)
{

}

void UpgradeC::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,192.f,1.f });


		Renderer->CreateFrameAnimationFolder("g_spire", FrameAnimation_DESC("g_spire", 0.1f));
		
		Renderer->ChangeFrameAnimation("g_spire");


	}



	MainUI = GetLevel()->CreateActor<UpgradeCUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 128.f, 192.f, 1.0f });
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

void UpgradeC::Update(float _DeltaTime)
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
