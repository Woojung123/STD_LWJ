

#include "PreCompile.h"
#include "MiniMapUnit.h"

MiniMapUnit::MiniMapUnit():
	Renderer(nullptr)
{
}

MiniMapUnit::~MiniMapUnit()
{
}

void MiniMapUnit::Start()
{
	{
		Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("MonMini.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -310,-220, -200 });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}
}


void MiniMapUnit::Update(float _DeltaTime)
{


	Renderer->GetTransform().SetLocalPosition({ (UnitPos.x/17) - 309.f ,(UnitPos.y / 17) - 217.f, -200 });

}