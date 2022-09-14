
#include "PreCompile.h"
#include "DragUI.h"
#include "Builder.h"
#include "MainMouse.h"

DragUI::DragUI() :
	m_Mouse(0),
	DragSize(0)
	, Renderer1(nullptr)
	, Renderer2(nullptr)
	, Renderer3(nullptr)
	, Renderer4(nullptr)
	, Renderer5(nullptr)
	, Renderer6(nullptr)
	, Renderer7(nullptr)
	, Renderer8(nullptr)
	, Renderer9(nullptr)
	, Renderer10(nullptr)
	, Renderer11(nullptr)
	, Renderer12(nullptr)

{
}

DragUI::~DragUI()
{
}


void DragUI::Start()
{
	{
		Renderer1 = CreateComponent<GameEngineUIRenderer>();
		Renderer1->SetTexture("ProbeWire.png");
		Renderer1->ScaleToTexture();
		Renderer1->GetTransform().SetLocalPosition({ -180.f,-210.f, -250.f });
		Renderer1->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer2 = CreateComponent<GameEngineUIRenderer>();
		Renderer2->SetTexture("ArconWire.png");
		Renderer2->ScaleToTexture();
		Renderer2->GetTransform().SetLocalPosition({ -130.f,-210.f, -250.f });
		Renderer2->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer3 = CreateComponent<GameEngineUIRenderer>();
		Renderer3->SetTexture("BuilderWire.png");
		Renderer3->ScaleToTexture();
		Renderer3->GetTransform().SetLocalPosition({ -80.f,-210.f, -250.f });
		Renderer3->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer4 = CreateComponent<GameEngineUIRenderer>();
		Renderer4->SetTexture("HydraCwire.png");
		Renderer4->ScaleToTexture();
		Renderer4->GetTransform().SetLocalPosition({ -30.f,-210.f, -250.f });
		Renderer4->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer5 = CreateComponent<GameEngineUIRenderer>();
		Renderer5->SetTexture("GardianWire.png");
		Renderer5->ScaleToTexture();
		Renderer5->GetTransform().SetLocalPosition({ 20.f,-210.f, -250.f });
		Renderer5->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer6 = CreateComponent<GameEngineUIRenderer>();
		Renderer6->SetTexture("TerranWire.png");
		Renderer6->ScaleToTexture();
		Renderer6->GetTransform().SetLocalPosition({ 70.f,-210.f, -250.f });
		Renderer6->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer7 = CreateComponent<GameEngineUIRenderer>();
		Renderer7->SetTexture("UltraWire.png");
		Renderer7->ScaleToTexture();
		Renderer7->GetTransform().SetLocalPosition({ -180.f,-260.f, -250.f });
		Renderer7->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer8 = CreateComponent<GameEngineUIRenderer>();
		Renderer8->SetTexture("ZealotWire.png");
		Renderer8->ScaleToTexture();
		Renderer8->GetTransform().SetLocalPosition({ -130.f,-260.f, -250.f });
		Renderer8->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer9 = CreateComponent<GameEngineUIRenderer>();
		Renderer9->SetTexture("ZearglingWire.png");
		Renderer9->ScaleToTexture();
		Renderer9->GetTransform().SetLocalPosition({ -80.f,-260.f, -250.f });
		Renderer9->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer10 = CreateComponent<GameEngineUIRenderer>();
		Renderer10->SetTexture("TerranWire.png");
		Renderer10->ScaleToTexture();
		Renderer10->GetTransform().SetLocalPosition({ -30.f,-260.f, -250.f });
		Renderer10->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer11 = CreateComponent<GameEngineUIRenderer>();
		Renderer11->SetTexture("RiverWire.png");
		Renderer11->ScaleToTexture();
		Renderer11->GetTransform().SetLocalPosition({ 20.f,-260.f, -250.f });
		Renderer11->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		Renderer12 = CreateComponent<GameEngineUIRenderer>();
		Renderer12->SetTexture("HighTwire.png");
		Renderer12->ScaleToTexture();
		Renderer12->GetTransform().SetLocalPosition({ 70.f,-260.f, -250.f });
		Renderer12->ChangeCamera(CAMERAORDER::UICAMERA);
	}




}


void DragUI::Update(float _DeltaTime)
{

	DragOnOff();

	



}

void DragUI::DragOnOff()
{

	if (DragSize == 0)
	{
		Renderer1->Off();
		Renderer2->Off();
		Renderer3->Off();
		Renderer4->Off();
		Renderer5->Off();
		Renderer6->Off();
		Renderer7->Off();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	if (DragSize == 1)
	{
		Renderer1->On();
		Renderer2->Off();
		Renderer3->Off();
		Renderer4->Off();
		Renderer5->Off();
		Renderer6->Off();
		Renderer7->Off();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 2)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->Off();
		Renderer4->Off();
		Renderer5->Off();
		Renderer6->Off();
		Renderer7->Off();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 3)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->Off();
		Renderer5->Off();
		Renderer6->Off();
		Renderer7->Off();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 4)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->Off();
		Renderer6->Off();
		Renderer7->Off();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 5)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->Off();
		Renderer7->Off();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 6)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->On();
		Renderer7->Off();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 7)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->On();
		Renderer7->On();
		Renderer8->Off();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 8)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->On();
		Renderer7->On();
		Renderer8->On();
		Renderer9->Off();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 9)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->On();
		Renderer7->On();
		Renderer8->On();
		Renderer9->On();
		Renderer10->Off();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 10)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->On();
		Renderer7->On();
		Renderer8->On();
		Renderer9->On();
		Renderer10->On();
		Renderer11->Off();
		Renderer12->Off();
	}
	else if (DragSize == 11)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->On();
		Renderer7->On();
		Renderer8->On();
		Renderer9->On();
		Renderer10->On();
		Renderer11->On();
		Renderer12->Off();
	}
	else if (DragSize == 12)
	{
		Renderer1->On();
		Renderer2->On();
		Renderer3->On();
		Renderer4->On();
		Renderer5->On();
		Renderer6->On();
		Renderer7->On();
		Renderer8->On();
		Renderer9->On();
		Renderer10->On();
		Renderer11->On();
		Renderer12->On();
	}







}


