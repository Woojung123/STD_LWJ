
#include "PreCompile.h"
#include "DarkMap.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>
#include "Builder.h"
#include "StageMain.h"
#include "DarkTile.h"

#include "StageMainCamera.h"

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
		Renderer->SetPipeLine("DarkMapShader");
		AtlasDataInst.FrameData.PosX = 0.0f;
		AtlasDataInst.FrameData.PosY = 0.0f;
		AtlasDataInst.FrameData.SizeX = 1.0f;
		AtlasDataInst.FrameData.SizeY = 1.0f;
		AtlasDataInst.PivotPos = float4::ZERO;

		Renderer->ShaderResources.SetConstantBufferLink("AtlasData", AtlasDataInst);
		Renderer->ShaderResources.SetConstantBufferLink("PixelData", PixelDataInst);
		//Renderer->ShaderResources.SetConstantBufferLink("RENDEROPTION", &Option, sizeof(Option));


		Renderer->SetTexture("Defense.png");
		Renderer->ScaleToTexture();
	
		
	}

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos .x , WorldPos .y , -1000.f, WorldPos.w });

	
}
void DarkMap::Update(float _DeltaTime)
{
	/*for (int i = 0; i < 10; ++i)
	{
		for (int j = 0; j < 10; ++j)
		{
			
			if (MainStage->DTilemap[i][j]->ScreenPos.x > 0 && MainStage->DTilemap[i][j]->ScreenPos.y)
			{

				float4 iTemp = MainStage->DTilemap[i][j]->ScreenPos;
				iTemp.y = -iTemp.y;
				Renderer->GetPixelData().Slice = iTemp;
			}
			
		}
	}*/

	//Renderer->renderOption.DeltaTime = _DeltaTime;
	//sumDelta += _DeltaTime;
	//Renderer->renderOption.SumDeltaTime = sumDelta;




	float4 BuilderPos = m_Bulder->GetTransform().GetWorldPosition();


	float4 Dummy = BuilderPos - M_Camera->GetTransform().GetWorldPosition();
	Dummy.x += 400.f;
	Dummy.y -= 300.f;

	


	
	Dummy.y = -Dummy.y;
	PixelDataInst.Slice = Dummy;

}