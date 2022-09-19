
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


	Font = CreateComponent<GameEngineFontRenderer>();
	// Font->ChangeCamera();
	Font->SetRenderingOrder(10000);
	Font->SetText("¾È³çÇÏ¼¼¿ä", "±Ã¼­");
	Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.0 });
	Font->SetSize(15);
	Font->SetScreenPostion({ 573, 0  });
	Font->ChangeCamera(CAMERAORDER::UICAMERA);


}

void TestUI::Update(float _DeltaTime)
{
	
	
	
	Font->SetText(std::to_string(m_Stage->Player_Gold) , "±Ã¼­");

}
