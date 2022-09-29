
#include "PreCompile.h"
#include "NexusUI.h"
#include "UnitBase.h"
#include "Nexus.h"

#include "Peobe.h"

NexusUI::NexusUI() :
	m_UpC(nullptr)
	, Col_ProUpgrade(nullptr)
{
}

NexusUI::~NexusUI()
{
}

void NexusUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("NexusWire.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -170.f,-240.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		StatusRenderer = CreateComponent<GameEngineUIRenderer>();
		StatusRenderer->SetTexture("Status_15.png");
		StatusRenderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		StatusRenderer->GetTransform().SetLocalPosition({ 0.f,-240.f, -280.f });
		StatusRenderer->ChangeCamera(CAMERAORDER::UICAMERA);



	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->GetTransform().SetLocalScale({ 70.f,60.f,1.f });
		Renderer->CreateFrameAnimationFolder("Corsair", FrameAnimation_DESC("Corsair", 0.1f));
		Renderer->GetTransform().SetLocalPosition({ 155.f,-250.f, -280.f });
		Renderer->ChangeFrameAnimation("Corsair");


	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("ProbeBut.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 255.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		ProGressMainRenderer = CreateComponent<GameEngineUIRenderer>();
		ProGressMainRenderer->SetTexture("ProrGressMain.png");
		ProGressMainRenderer->ScaleToTexture();
		ProGressMainRenderer->GetTransform().SetLocalPosition({ -20.f,-280.f, -300.f });
		ProGressMainRenderer->ChangeCamera(CAMERAORDER::UICAMERA);
		ProGressMainRenderer->Off();
	}


	{
		ProGressUpRenderer = CreateComponent<GameEngineUIRenderer>();
		ProGressUpRenderer->SetTexture("ProGressUp.png");
		ProGressUpRenderer->ScaleToTexture();
		ProGressUpRenderer->GetTransform().SetLocalPosition({ -20.f,-280.f, -301.f });
		ProGressUpRenderer->ChangeCamera(CAMERAORDER::UICAMERA);
		ProGressUpRenderer->Off();
		ProGressUpRenderer->renderOption.Option00 = 15;
	}


	for(int i = 0; i <5; ++i)
	{
		ProbeRender[i] = CreateComponent<GameEngineUIRenderer>();
		ProbeRender[i]->SetTexture("ProbeWire.png");
		ProbeRender[i]->ScaleToTexture();
		ProbeRender[i]->GetTransform().SetLocalPosition({ -120.f + i * 40.f ,-250.f, -301.f });
		ProbeRender[i]->ChangeCamera(CAMERAORDER::UICAMERA);
		ProbeRender[i]->Off();
	}


	ProbeRender[0]->GetTransform().SetLocalPosition({ -80.f  ,-210.f, -301.f });


	{
		Col_ProUpgrade = CreateComponent<GameEngineCollision>();
		Col_ProUpgrade->GetTransform().SetLocalScale({ 36.f, 34.f, 1.f });
		Col_ProUpgrade->GetTransform().SetLocalPosition({ 255.f,-170.f, -250.f });
		Col_ProUpgrade->ChangeOrder(OBJECTORDER::UI);


	}

	




}
void NexusUI::Update(float _DeltaTime)
{

	Col_ProUpgrade->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&NexusUI::Col_Pro, this, std::placeholders::_1, std::placeholders::_2)
	);


	if (MakeCount > 0)
	{
		ProGressMainRenderer->On();
		ProGressUpRenderer->On();
		StatusRenderer->Off();
		UpTime += _DeltaTime;

		ProGressUpRenderer->GetPixelData().Slice.x = UpTime;

		
		ProbeRender[MakeCount - 1]->On();

		for (int i = 0; i <= MakeCount; ++i)
		{
		

			if (UpTime >= 1.f)
			{
				UpTime = 0.f;
				ProbeRender[MakeCount - 1]->Off();

				Peobe* TestUni = GetLevel()->CreateActor<Peobe>(OBJECTORDER::Probe);
				TestUni->GetTransform().SetWorldPosition({ -512.f,-240.f,0.f });
				TestUni->m_MainStage = m_UpC->m_MainStage;

				--MakeCount;
			}

		}


		


	
	}
	else
	{


		ProGressMainRenderer->Off();
		ProGressUpRenderer->Off();
		StatusRenderer->On();

	}

	

}

bool NexusUI::Col_Pro(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	if (true == GameEngineInput::GetInst()->IsDown("LCUpClick"))
	{
		if (m_UpC->m_MainStage->Player_Gold < 150)
		{
			return true;
		}

		m_UpC->m_MainStage->Player_Gold -= 150;
		m_UpC->m_bClickCheck = true;

		++MakeCount;
		if (MakeCount >= 5)
		{
			MakeCount = 5;
		}

	}

	return true;
}
