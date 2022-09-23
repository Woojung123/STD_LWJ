
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



	{
		MissionTerRender = CreateComponent<GameEngineUIRenderer>();
		MissionTerRender->SetTexture("TerMisson.png");
		MissionTerRender->ScaleToTexture();
		MissionTerRender->GetTransform().SetLocalPosition({ -380.f,140.f, -250.f });
		MissionTerRender->ChangeCamera(CAMERAORDER::UICAMERA);
		MissionTerRender->Off();
	}


	{
		MissionProRender = CreateComponent<GameEngineUIRenderer>();
		MissionProRender->SetTexture("ProMisson.png");
		MissionProRender->ScaleToTexture();
		MissionProRender->GetTransform().SetLocalPosition({ -380.f,110.f, -250.f });
		MissionProRender->ChangeCamera(CAMERAORDER::UICAMERA);
		MissionProRender->Off();
	}


	{
		MissionZergRender = CreateComponent<GameEngineUIRenderer>();
		MissionZergRender->SetTexture("ZergMission.png");
		MissionZergRender->ScaleToTexture();
		MissionZergRender->GetTransform().SetLocalPosition({ -380.f,80.f, -250.f });
		MissionZergRender->ChangeCamera(CAMERAORDER::UICAMERA);
		MissionZergRender->Off();
	}


	{
		MissionAirRender = CreateComponent<GameEngineUIRenderer>();
		MissionAirRender->SetTexture("AirMission.png");
		MissionAirRender->ScaleToTexture();
		MissionAirRender->GetTransform().SetLocalPosition({ -380.f,50.f, -250.f });
		MissionAirRender->ChangeCamera(CAMERAORDER::UICAMERA);
		MissionAirRender->Off();
	}

	{
		FontAMission = CreateComponent<GameEngineFontRenderer>();
		FontAMission->SetRenderingOrder(10000);
		FontAMission->SetText("A", "Starcraft");
		FontAMission->SetColor({ 1.0f, 0.0f, 0.0f, 1.0 });
		FontAMission->SetSize(30);
		FontAMission->SetScreenPostion({ 1, 110 });
		FontAMission->ChangeCamera(CAMERAORDER::UICAMERA);
		FontAMission->Off();
	}


	{
		FontBMission = CreateComponent<GameEngineFontRenderer>();
		FontBMission->SetRenderingOrder(10000);
		FontBMission->SetText("B", "Starcraft");
		FontBMission->SetColor({ 0.0f, 0.0f, 1.0f, 1.0 });
		FontBMission->SetSize(25);
		FontBMission->SetScreenPostion({ 1, 80 });
		FontBMission->ChangeCamera(CAMERAORDER::UICAMERA);
		FontBMission->Off();
	}



	{
		FontCMission = CreateComponent<GameEngineFontRenderer>();
		FontCMission->SetRenderingOrder(10000);
		FontCMission->SetText("C", "Starcraft");
		FontCMission->SetColor({ 0.0f, 1.0f, 0.0f, 1.0 });
		FontCMission->SetSize(25);
		FontCMission->SetScreenPostion({ 1, 50 });
		FontCMission->ChangeCamera(CAMERAORDER::UICAMERA);
		FontCMission->Off();
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


	if (m_Stage->MissionC)
	{
		FontCMission->On();
	}
	if (m_Stage->MissionB)
	{
		FontBMission->On();
	}
	if (m_Stage->MissionA)
	{
		FontAMission->On();
	}
	if (m_Stage->MissionZerg)
	{

		MissionZergRender->On();
	}
	if (m_Stage->MissionPro)
	{
		MissionProRender->On();
	}
	if (m_Stage->MissionTer)
	{
		MissionTerRender->On();
	
	}
	if (m_Stage->MissionAir)
	{
		MissionAirRender->On();
	}





}
