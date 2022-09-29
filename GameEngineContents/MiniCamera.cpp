

#include "PreCompile.h"
#include "MiniCamera.h"
#include "StageMainCamera.h"

MiniCamera::MiniCamera() :
	Renderer(nullptr)
{
}

MiniCamera::~MiniCamera()
{
}

void MiniCamera::Start()
{
	{
		Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("SDSD1.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -310,-220, -300 });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	float4 Scale = Renderer->GetTransform().GetLocalScale();


	{
		Collision = CreateComponent<GameEngineCollision>();

		Collision->GetTransform().SetLocalScale(Scale);
		Collision->GetTransform().SetLocalPosition({ -310,-220, -300 });

	//	Collision->SetParent(Renderer);
		Collision->ChangeOrder(OBJECTORDER::UI);


	}
}


void MiniCamera::Update(float _DeltaTime)
{
	MailCamera->MiniOnOff = false;

	Renderer->GetTransform().SetLocalPosition({ (UnitPos.x / 17) - 315.f ,(UnitPos.y / 17) - 217.f, -300 });
	Collision->GetTransform().SetLocalPosition({ (UnitPos.x / 17) - 315.f ,(UnitPos.y / 17) - 217.f, -300 });


	float4 MiniPos = Renderer->GetTransform().GetLocalPosition();


	// x -253 -376
	//y -240 -193
	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&MiniCamera::Collcheck, this, std::placeholders::_1, std::placeholders::_2)
	);



}

bool MiniCamera::Collcheck(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	MailCamera->MiniOnOff = true;


	float MouseScreenPosX = GetLevel()->GetMainCamera()->GetMouseScreenPosition().x;
	float MouseScreenPosY = GetLevel()->GetMainCamera()->GetMouseScreenPosition().y;

	MouseScreenPosX -= 400.f;
	MouseScreenPosY -= 300.f;
	MouseScreenPosY = -MouseScreenPosY;



	if (MouseScreenPosX<= -376.f)
	{
		MouseScreenPosX = -376.f;

	}

	if (MouseScreenPosX >= -253.f)
	{
		MouseScreenPosX = -253.f;

	}


	if (MouseScreenPosY <= -240.f)
	{
		MouseScreenPosY = -240.f;

	}


	if (MouseScreenPosY >= -193.f)
	{
		MouseScreenPosY = -193.f;

	}




	if (true == GameEngineInput::GetInst()->IsDown("LeftClick"))
	{
		

		Renderer->GetTransform().SetLocalPosition({ MouseScreenPosX ,MouseScreenPosY , -300 });
		Collision->GetTransform().SetLocalPosition({ MouseScreenPosX ,MouseScreenPosY , -300 });

		float4 MiniPos = Renderer->GetTransform().GetLocalPosition();




		MailCamera->GetTransform().SetWorldPosition({ (MiniPos.x + 315.f) * 17 ,(MiniPos.y + 217.f) * 17 });

	}


	if (true == GameEngineInput::GetInst()->IsPress("LeftClick"))
	{



		Renderer->GetTransform().SetLocalPosition({ MouseScreenPosX ,MouseScreenPosY , -300 });
		Collision->GetTransform().SetLocalPosition({ MouseScreenPosX ,MouseScreenPosY , -300 });


		float4 MiniPos = Renderer->GetTransform().GetLocalPosition();

		MailCamera->GetTransform().SetWorldPosition({ (MiniPos.x + 315.f ) * 17 ,(MiniPos.y + 217.f) * 17 });
		//MailCamera->GetTransform().SetWorldPosition({0.f,0.f });


	}


	if (true == GameEngineInput::GetInst()->IsFree("LeftClick"))
	{

	}





	return true;

}
