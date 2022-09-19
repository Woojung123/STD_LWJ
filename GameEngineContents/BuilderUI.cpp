

#include "PreCompile.h"
#include "BuilderUI.h"
#include "Builder.h"
#include "MainMouse.h"

#include "StageMain.h"


BuilderUI::BuilderUI() :
	 m_Builder(0)
	,CollisionBuild(0)
	,CollisionMake(0)
{
}

BuilderUI::~BuilderUI() 
{
}


void BuilderUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("corsair.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -170.f,-240.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Status_9.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 0.f,-240.f, -280.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);



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
		Renderer->SetTexture("MoveUI.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 255.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("ClickUI.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 310.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("StopUI.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 370.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);

	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("pyl.png");
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetLocalPosition({ 315.f,-270.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		CollisionMake = CreateComponent<GameEngineCollision>();
		CollisionMake->GetTransform().SetLocalScale({ 36.f, 34.f, 1.f });
		CollisionMake->GetTransform().SetLocalPosition({ 255.f,-270.f, -250.f });
		CollisionMake->ChangeOrder(OBJECTORDER::UI);


	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("HapUI.png");
		Renderer->ScaleToTexture();
		Renderer->GetTransform().SetLocalPosition({ 255.f,-270.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		CollisionBuild = CreateComponent<GameEngineCollision>();
		CollisionBuild->GetTransform().SetLocalScale({ 36.f, 34.f, 1.f });
		CollisionBuild->GetTransform().SetLocalPosition({ 315.f,-270.f, -250.f });
		CollisionBuild->ChangeOrder(OBJECTORDER::UI);


	}








	GameEngineInput::GetInst()->CreateKey("LCClick", VK_LBUTTON);










}


void BuilderUI::Update(float _DeltaTime)
{


	CollisionBuild->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&BuilderUI::BuildCollision, this, std::placeholders::_1, std::placeholders::_2)
	);


	CollisionMake->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&BuilderUI::MakeCollision, this, std::placeholders::_1, std::placeholders::_2)
	);
}



bool BuilderUI::BuildCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (true == GameEngineInput::GetInst()->IsDown("LCClick"))
	{

		if (m_Builder->m_Stage->Player_Gold >= 50)
		{
			m_Builder->m_bClickCheck = true;
			m_Builder->m_MainMouse->BuildCheck = true;
			m_Builder->m_MainMouse->PlusCheck = false;
		}
		

	}
	
	return false;
}

bool BuilderUI::MakeCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	if (true == GameEngineInput::GetInst()->IsDown("LCClick"))
	{
		m_Builder->m_bClickCheck = true;
		m_Builder->m_MainMouse->PlusCheck = true;
		m_Builder->m_MainMouse->BuildCheck = false;
	}

	
	return false;
}
