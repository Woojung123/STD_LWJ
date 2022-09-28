
#include "PreCompile.h"
#include "Nexus.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include "NexusUI.h"
#include "MiniMapPlayer.h"




Nexus::Nexus()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(200.f)
	, AttCheck(false)
	, ListLastCheck(false)
	, MainUI(nullptr)
{
}

Nexus::~Nexus()
{
}


void Nexus::AttEnd(const FrameAnimation_DESC& _Info)
{

}

void Nexus::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("Nexus_0.png");
		Renderer->ScaleToTexture();


	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->SetTexture("Nexus_0.png");
		ShadowRenderer->ScaleToTexture();

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



	MainUI = GetLevel()->CreateActor<NexusUI>(OBJECTORDER::UI);
	MainUI->m_UpC = (this);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 120.0f, 120.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);

	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select9.png");
		ClickRenderer->ScaleToTexture();
		ClickRenderer->GetTransform().SetLocalPosition({ 0.f,-5.f,1.f });
	}



	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);



}

void Nexus::Update(float _DeltaTime)
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

