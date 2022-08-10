

#include "PreCompile.h"
#include "MiniMap.h"

MiniMap::MiniMap()
{
}

MiniMap::~MiniMap()
{
}

void MiniMap::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("MiniMap.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -310,-220, -149 });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}
}
