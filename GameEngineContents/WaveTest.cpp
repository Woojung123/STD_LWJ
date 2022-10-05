

#include "PreCompile.h"
#include "WaveTest.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

WaveTest::WaveTest()
{
}

WaveTest::~WaveTest()
{
}


void WaveTest::Start()
{

	//{
	//	Renderer = CreateComponent<GameEngineTextureRenderer>();
	//	
	//	Renderer->SetPipeLine("TsetWave");
	//	AtlasDataInst.FrameData.PosX = 0.0f;
	//	AtlasDataInst.FrameData.PosY = 0.0f;
	//	AtlasDataInst.FrameData.SizeX = 1.0f;
	//	AtlasDataInst.FrameData.SizeY = 1.0f;
	//	AtlasDataInst.PivotPos = float4::ZERO;
	//	Renderer->ShaderResources.SetConstantBufferLink("WaveAtlasData", AtlasDataInst);
	//	Renderer->ShaderResources.SetConstantBufferLink("PixelWData", PixelDataInst);
	//	Renderer->SetTexture("WaveTset.png");
	//	Renderer->ScaleToTexture();
	//}
	//float4 WorldPos = GetTransform().GetWorldPosition();
	//GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , 100.f, WorldPos.w });


}
void WaveTest::Update(float _DeltaTime)
{
}