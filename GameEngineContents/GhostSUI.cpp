

#include "PreCompile.h"
#include "GhostSUI.h"

GhostSUI::GhostSUI()
{
}

GhostSUI::~GhostSUI()
{
}

void GhostSUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("DarkTempler.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -170.f,-240.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Status_4.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 0.f,-240.f, -280.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);



	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->GetTransform().SetLocalScale({ 70.f,60.f,1.f });
		Renderer->CreateFrameAnimationFolder("Aldaris0", FrameAnimation_DESC("Aldaris0", 0.1f));
		Renderer->GetTransform().SetLocalPosition({ 155.f,-250.f, -280.f });
		Renderer->ChangeFrameAnimation("Aldaris0");


	}

	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("MoveUI.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 255.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("ClickUI.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 310.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("StopUI.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 370.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);

	}



}
