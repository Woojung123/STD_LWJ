
#include "PreCompile.h"
#include "DarkMap.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "Builder.h"
#include "StageMain.h"
#include "DarkTile.h"


DarkMap::DarkMap()	:
	m_Bulder(nullptr)
{
}

DarkMap::~DarkMap()
{
}


void DarkMap::Start()
{

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("Defen.png");
		Renderer->ScaleToTexture();
		Renderer->renderOption.Option00 = 3;
		Renderer->GetPixelData().MulColor = {0.f,0.f,0.f,1.f};
	}

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos .x , WorldPos .y , -1000.f, WorldPos.w });

	
}
void DarkMap::Update(float _DeltaTime)
{
	for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			
			if (MainStage->DTilemap[i][j]->ScreenPos.x >= 400.f)
			{
				Renderer->GetPixelData().Slice = MainStage->DTilemap[i][j]->ScreenPos;
			}
			
		}
	}



}