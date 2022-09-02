

#include "PreCompile.h"
#include "MiniCamera.h"

MiniCamera::MiniCamera() :
	Renderer(nullptr)
{
}

MiniCamera::~MiniCamera()
{
}

void MiniCamera::Start()
{
	{
		Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("SDSD1.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -310,-220, -200 });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}
}


void MiniCamera::Update(float _DeltaTime)
{


	Renderer->GetTransform().SetLocalPosition({ (UnitPos.x / 17) - 315.f ,(UnitPos.y / 17) - 217.f, -210 });

}