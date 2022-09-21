
#include "PreCompile.h"
#include "TestUI.h"
#include "StageMain.h"
TestUI::TestUI() :
	m_Stage(0)
{
}

TestUI::~TestUI()
{
}

void TestUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Ui.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 0, 0, -150 });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}
	
	{
		BaseEndingRenderer = CreateComponent<GameEngineUIRenderer>();
		BaseEndingRenderer->SetTexture("UiBase.png");
		BaseEndingRenderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		BaseEndingRenderer->GetTransform().SetLocalPosition({ 0, 0, -150 });
		BaseEndingRenderer->ChangeCamera(CAMERAORDER::UICAMERA);
		BaseEndingRenderer->Off();
	}


	{
		Font = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		Font->SetRenderingOrder(10000);
		Font->SetText("¾È³çÇÏ¼¼¿ä", "±Ã¼­");
		Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.0 });
		Font->SetSize(15);
		Font->SetScreenPostion({ 573, 0 });
		Font->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		VictoryFont = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		VictoryFont->SetRenderingOrder(10000);
		VictoryFont->SetText("Victory", "Starcraft");
		VictoryFont->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
		VictoryFont->SetSize(15);
		VictoryFont->SetScreenPostion({ 360, 335 });
		VictoryFont->ChangeCamera(CAMERAORDER::UICAMERA);
		VictoryFont->SetParent(BaseEndingRenderer);
	}


	{
		OkFont = CreateComponent<GameEngineFontRenderer>();
		// Font->ChangeCamera();
		OkFont->SetRenderingOrder(10000);
		OkFont->SetText("congratulations! \n \nyou are victorious! ", "Starcraft");
		OkFont->SetColor({ 1.0f, 1.0f, 1.0f, 1.0 });
		OkFont->SetSize(15);
		OkFont->SetLeftAndRightSort(LeftAndRightSort::CENTER);
		OkFont->SetScreenPostion({ 400, 260 });
		OkFont->ChangeCamera(CAMERAORDER::UICAMERA);
		OkFont->SetParent(BaseEndingRenderer);
	}



}

void TestUI::Update(float _DeltaTime)
{
	
	
	

	if (m_Stage->GameFinishBool)
	{
		BaseEndingRenderer->On();
	}
	else
	{
		BaseEndingRenderer->Off();
	}
	Font->SetText(std::to_string(m_Stage->Player_Gold) , "±Ã¼­");






}
