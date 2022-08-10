

#include "PreCompile.h"
#include "ProbeSUI.h"

ProbeSUI::ProbeSUI()
{
}

ProbeSUI::~ProbeSUI()
{
}

void ProbeSUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Probe.png");
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
		Renderer->CreateFrameAnimationFolder("Probe0", FrameAnimation_DESC("Probe0", 0.1f));
		Renderer->GetTransform().SetLocalPosition({ 155.f,-250.f, -280.f });
		Renderer->ChangeFrameAnimation("Probe0");


	}




}
