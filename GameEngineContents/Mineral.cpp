
#include "PreCompile.h"
#include "Mineral.h"
#include "GlobalContentsValue.h"
#include "MiniMapPlayer.h"




Mineral::Mineral()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(200.f)
	, AttCheck(false)
	, ListLastCheck(false)
{
}

Mineral::~Mineral()
{
}


void Mineral::AttEnd(const FrameAnimation_DESC& _Info)
{

}

void Mineral::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });



	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("Mineral_0.png");
		Renderer->ScaleToTexture();


	}

	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->SetTexture("Mineral_0.png");
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




	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Mineral);

	}



	



}

void Mineral::Update(float _DeltaTime)
{

	


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}

