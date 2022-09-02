

#include "PreCompile.h"
#include "MiniMapPlayer.h"

MiniMapPlayer::MiniMapPlayer() :
	Renderer(nullptr)
{
}

MiniMapPlayer::~MiniMapPlayer()
{
}

void MiniMapPlayer::Start()
{
	{
		Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("PlayerMonMini.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -310,-220, -200 });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}
}


void MiniMapPlayer::Update(float _DeltaTime)
{


	Renderer->GetTransform().SetLocalPosition({ (UnitPos.x / 17) - 309.f ,(UnitPos.y / 17) - 217.f, -200 });

}