
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
		Renderer->SetPipeLine("DarkMapShaderTest");
		AtlasDataInst.FrameData.PosX = 0.0f;
		AtlasDataInst.FrameData.PosY = 0.0f;
		AtlasDataInst.FrameData.SizeX = 1.0f;
		AtlasDataInst.FrameData.SizeY = 1.0f;
		AtlasDataInst.PivotPos = float4::ZERO;

		Renderer->ShaderResources.SetConstantBufferLink("AtlasData", AtlasDataInst);
		Renderer->ShaderResources.SetConstantBufferLink("PixelTData", PixelDataInst);
		//Renderer->ShaderResources.SetConstantBufferLink("RENDEROPTION", &Option, sizeof(Option));


		Renderer->SetTexture("Defense.png");
		Renderer->ScaleToTexture();
	
		
	}

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos .x , WorldPos .y , -1000.f, WorldPos.w });



	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			PosTile[i][j] = { -1200.f + i * 50.f , -700.f + j * 28.f , 100.f, 0.f };

		}

	}




}
void DarkMap::Update(float _DeltaTime)
{

	float4 BuilderPos = m_Bulder->GetTransform().GetWorldPosition();
	float4 BuilderPos2 = BuilderPos;
	BuilderPos2.z = 100.f;


	for (int i = 0; i < 50; ++i)
	{
		for (int j = 0; j < 50; ++j)
		{
			float4 TarGetPos = PosTile[i][j];
			float4 Dist = BuilderPos2 - TarGetPos;
			float MonLen = Dist.Length();


			if (MonLen <= 100.f)
			{


				PosTile[i][j].z = 0.f;

			}
			float4 Dummy2 = PosTile[i][j] - M_Camera->GetTransform().GetWorldPosition();
			Dummy2.x += 400.f;
			Dummy2.y -= 300.f;
			Dummy2.y = -Dummy2.y;
			


		/*	if (Dummy2.x >= 0.f && Dummy2.x <= 800.f && Dummy2.y <= 600.f && Dummy2.y >= 0.f)
			{
				Dummy2.z = 100.f;
			}*/
			PixelDataInst.Pos[i][j] = Dummy2;



			

		}

	}



	float4 Dummy = BuilderPos - M_Camera->GetTransform().GetWorldPosition();
	Dummy.x += 400.f;
	Dummy.y -= 300.f;

	


	
	Dummy.y = -Dummy.y;
	PixelDataInst.Slice = Dummy;

}