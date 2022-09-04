
#include "PreCompile.h"
#include "DragoonCUI.h"

DragoonCUI::DragoonCUI()
{
}

DragoonCUI::~DragoonCUI()
{
}

void DragoonCUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Dragon.png");
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
		Renderer->CreateFrameAnimationFolder("Dragoon0", FrameAnimation_DESC("Dragoon0", 0.1f));
		Renderer->GetTransform().SetLocalPosition({ 155.f,-250.f, -280.f });
		Renderer->ChangeFrameAnimation("Dragoon0");


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
