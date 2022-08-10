

#include "PreCompile.h"
#include "MainMouse.h"
#include "StageMainCamera.h"
#include"UnitBase.h"


MainMouse::MainMouse()
{
}

MainMouse::~MainMouse()
{
}


void MainMouse::Start()
{

	float4 WorldPos = GetTransform().GetWorldPosition();
	WorldPos.x = GetLevel()->GetMainCamera()->GetMouseWorldPosition().x;
	WorldPos.y = GetLevel()->GetMainCamera()->GetMouseWorldPosition().y;
	WorldPos.z = -151.f;
	GetTransform().SetWorldPosition(WorldPos);




	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 1.f, 1.f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Mouse);
	}

	{
		GameEngineTextureRenderer* Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("PlayerMonMini.png");
		Renderer->ScaleToTexture();

		//Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	
		GameEngineInput::GetInst()->CreateKey("LeftClick", VK_LBUTTON);
	


}


void MainMouse::Update(float _DeltaTime)
{

	float4 WorldPos = GetTransform().GetWorldPosition();
	WorldPos.x = GetLevel()->GetMainCamera()->GetMouseWorldPosition().x;
	WorldPos.y = GetLevel()->GetMainCamera()->GetMouseWorldPosition().y;
	WorldPos.z = -151.f;
	GetTransform().SetWorldPosition(WorldPos);


	




	//Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
	//	std::bind(&MainMouse::AllCollision, this, std::placeholders::_1, std::placeholders::_2)
	//);

	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Player, CollisionType::CT_OBB2D,
		std::bind(&MainMouse::AllCollision, this, std::placeholders::_1, std::placeholders::_2)
	);

	//Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::UI, CollisionType::CT_OBB2D,
	//	std::bind(&MainMouse::UICollision, this, std::placeholders::_1, std::placeholders::_2)
	//);



}

bool MainMouse::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{



	return false;
}

bool MainMouse::PlayerCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	return false;
}

bool MainMouse::UICollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{



	return false;
}

bool MainMouse::AllCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	if (true == GameEngineInput::GetInst()->IsDown("LeftClick"))
	{
		ClickReset();

		((UnitBase*)_Other->GetActor())->m_bClickCheck = true;

	}
	return false;
}

void MainMouse::ClickReset()
{
	//{
	//	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);


	//	auto	iter = Group.begin();
	//	auto	iterEnd = Group.end();

	//	for (; iter != iterEnd; ++iter)
	//	{
	//		((UnitBase*)(*iter))->m_bClickCheck = false;
	//	}


	//}

	{
		std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Player);


		auto	iter = Group.begin();
		auto	iterEnd = Group.end();

		for (; iter != iterEnd; ++iter)
		{
			((UnitBase*)(*iter))->m_bClickCheck = false;
		}


	}




}
