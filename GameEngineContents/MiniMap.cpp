

#include "PreCompile.h"
#include "MiniMap.h"
#include "Builder.h"
#include "MiniMapPlayer.h"

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


	{
		DMiniRenderer = CreateComponent<GameEngineUIRenderer>();
	

		DMiniRenderer->SetPipeLine("DarkMapShader");
		AtlasDataInst.FrameData.PosX = 0.0f;
		AtlasDataInst.FrameData.PosY = 0.0f;
		AtlasDataInst.FrameData.SizeX = 1.0f;
		AtlasDataInst.FrameData.SizeY = 1.0f;
		AtlasDataInst.PivotPos = float4::ZERO;

		DMiniRenderer->ShaderResources.SetConstantBufferLink("AtlasData", AtlasDataInst);
		DMiniRenderer->ShaderResources.SetConstantBufferLink("PixelData", PixelDataInst);

		DMiniRenderer->SetTexture("Sbeacon.png");
		DMiniRenderer->ScaleToTexture();
		DMiniRenderer->GetTransform().SetLocalPosition({ -310,-217, -249 });
		DMiniRenderer->ChangeCamera(CAMERAORDER::UICAMERA);
	

	}
}

void MiniMap::Update(float _DeltaTime)
{


	if (GameEngineInput::GetInst()->IsDown("DarkMapD"))
	{
		DMiniRenderer->Off();

	}


	float4 BuilderPos = m_Bulder->MiniPlayUnit->Renderer->GetTransform().GetLocalPosition();


	BuilderPos.x += 400.f;
	BuilderPos.y -= 300.f;

	
	BuilderPos.y = -BuilderPos.y;
	BuilderPos.z = 100.f;
	PixelDataInst.Slice = BuilderPos;

}
