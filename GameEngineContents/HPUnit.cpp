
#include "PreCompile.h"
#include "HPUnit.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"





HPUnit::HPUnit()
{
}

HPUnit::~HPUnit()
{
}



void HPUnit::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("MineLife.png");
		Renderer->ScaleToTexture();


	}




}

void HPUnit::Update(float _DeltaTime)
{
	

}

