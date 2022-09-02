#include "PreCompile.h"
#include "UpgradeS.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DraBall.h"
#include "UpgradeSUI.h"
#include "MiniMapPlayer.h"




UpgradeS::UpgradeS()
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

UpgradeS::~UpgradeS()
{
}


void UpgradeS::AttEnd(const FrameAnimation_DESC& _Info)
{

}

void UpgradeS::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("Adun.png");
		Renderer->ScaleToTexture();


	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->SetTexture("Adun.png");
		ShadowRenderer->ScaleToTexture();

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



	MainUI = GetLevel()->CreateActor<UpgradeSUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
		
	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select5.png");
		ClickRenderer->ScaleToTexture();
		ClickRenderer->GetTransform().SetLocalPosition({ 0.f,-5.f,1.f });
	}



	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);



}

void UpgradeS::Update(float _DeltaTime)
{

	MiniPlayUnit->UnitPos = GetTransform().GetWorldPosition();

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

