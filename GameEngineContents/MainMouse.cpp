

#include "PreCompile.h"
#include "MainMouse.h"
#include "StageMainCamera.h"
#include"UnitBase.h"
#include "Builder.h"

#include "BuildImage.h"

#include "MiniMapPlayer.h"




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

	BuildColorCheck = false;
	BuildCheck = false;
	PlusCheck = false;
	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 1.f, 1.f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Mouse);
	}

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("PlayerMonMini.png");
		Renderer->ScaleToTexture();

	}


	{
		BuildRenderer = CreateComponent<GameEngineTextureRenderer>();
		BuildRenderer->SetTexture("PylonBuild.png");
		BuildRenderer->ScaleToTexture();

	}
	
	GameEngineInput::GetInst()->CreateKey("LeftClick", VK_LBUTTON);
	GameEngineInput::GetInst()->CreateKey("BuilderClick", '1');


}



void MainMouse::Update(float _DeltaTime)
{

	float4 WorldPos = GetTransform().GetWorldPosition();
	WorldPos.x = GetLevel()->GetMainCamera()->GetMouseWorldPosition().x;
	WorldPos.y = GetLevel()->GetMainCamera()->GetMouseWorldPosition().y;
	WorldPos.z = -151.f;
	GetTransform().SetWorldPosition(WorldPos);

	if (true == GameEngineInput::GetInst()->IsDown("BuilderClick"))
	{

		ClickReset();
		std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Player);


		auto	iter = Group.begin();
		auto	iterEnd = Group.end();

		for (; iter != iterEnd; ++iter)
		{
			if (((UnitBase*)(*iter))->m_Type == UNITTYPE::Builder)
			{
				((UnitBase*)(*iter))->m_bClickCheck = true;
			}

		}

	}





	if (BuildCheck)
	{
		BuildRenderer->On();
	}
	else
	{
		BuildRenderer->Off();
	}

	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Player, CollisionType::CT_OBB2D,
		std::bind(&MainMouse::AllCollision, this, std::placeholders::_1, std::placeholders::_2)
	);

	if (true == Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Player, CollisionType::CT_OBB2D))
	{
		BuildColorCheck = true;

	}
	else
	{
		if (true == GameEngineInput::GetInst()->IsDown("LeftClick"))
		{
			ClickReset();
		}
		BuildColorCheck = false;
	}


	
	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::TileMap, CollisionType::CT_OBB2D,
		std::bind(&MainMouse::PlayerCollision, this, std::placeholders::_1, std::placeholders::_2)
	);


	if (true == Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::TileMap, CollisionType::CT_OBB2D))
	{
		
	
	}
	else
	{
		if (true == GameEngineInput::GetInst()->IsDown("LeftClick"))
		{
			BuildCheck = false;
			PlusCheck = false;
		}

		BuildRenderer->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
		BuildRenderer->GetColorData().MulColor = { 1.f,0.f,0.f,0.5f };

	}


}

bool MainMouse::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{



	return false;
}

bool MainMouse::PlayerCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	BuildRenderer->GetTransform().SetWorldPosition(_Other->GetTransform().GetWorldPosition());
		

	if (!BuildColorCheck)
	{
		BuildRenderer->GetColorData().MulColor = { 0.f,1.f,0.f,0.5f };
		if (true == GameEngineInput::GetInst()->IsDown("LeftClick"))
		{
			if (BuildCheck)
			{
				BuildCheck = false;
				PlusCheck = false;
				m_Builder->BuildCheck = true;
				m_Builder->BuildPos = BuildRenderer->GetTransform().GetWorldPosition();


				
			}
		
			



		}


	}
	
	
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

		UNITTYPE _type = ((UnitBase*)_Other->GetActor())->m_Type;

		ClickReset();
		int Typecount = 0;
		int Deletcount = 0;
		if (PlusCheck)
		{

			//타워 몇개인지 체크
			{
				std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Player);


				auto	iter = Group.begin();
				auto	iterEnd = Group.end();

				for (; iter != iterEnd; ++iter)
				{
					if (_type != UNITTYPE::NULLTYPE)
					{
						if (_type == ((UnitBase*)(*iter))->m_Type)
						{
							++Typecount;

						}

					}
				


				}

			}
			
			if (_type == UNITTYPE::ProbeS || _type == UNITTYPE::HydraS || _type == UNITTYPE::GhostS
				|| _type == UNITTYPE::DroneS )
			{
				Typecount = 0;
			}


			//타워 삭제
			if (Typecount >= 3)
			{

				std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Player);


				auto	iter = Group.begin();
				auto	iterEnd = Group.end();

				for (; iter != iterEnd; ++iter)
				{

					if (((UnitBase*)_Other->GetActor()) != ((UnitBase*)(*iter)))
					{
						if (((UnitBase*)_Other->GetActor())->m_Type == ((UnitBase*)(*iter))->m_Type)
						{
							
							(*iter)->Death();
							((UnitBase*)(*iter))->MiniPlayUnit->Death();
							++Deletcount;

							if (Deletcount == 2)
								break;

						}

					}


				}


				_Other->GetActor()->Death();
				((UnitBase*)_Other->GetActor())->MiniPlayUnit->Death();
				if (_type == UNITTYPE::ZerglingC || _type == UNITTYPE::CorsairC || _type == UNITTYPE::DraC
					|| _type == UNITTYPE::GhostC || _type == UNITTYPE::HydraC
					|| _type == UNITTYPE::MarinC || _type == UNITTYPE::ZealotC)
				{

					m_Builder->BuildCheck = true;
					m_Builder->BuildMake = true;
					m_Builder->GradeType = 1;
					m_Builder->BuildPos = BuildRenderer->GetTransform().GetWorldPosition();

				}


				if (_type == UNITTYPE::ArbitorB || _type == UNITTYPE::DarkTB 
					|| _type == UNITTYPE::HighTB || _type == UNITTYPE::PhotoB
					|| _type == UNITTYPE::SunkenB || _type == UNITTYPE::UltraB)
				{

					m_Builder->BuildCheck = true;
					m_Builder->BuildMake = true;
					m_Builder->GradeType = 2;
					m_Builder->BuildPos = BuildRenderer->GetTransform().GetWorldPosition();

				}


				if (_type == UNITTYPE::ArconA || _type == UNITTYPE::CarrierA || _type == UNITTYPE::GardianA
					|| _type == UNITTYPE::MutalA || _type == UNITTYPE::RiverA)
				{

					m_Builder->BuildCheck = true;
					m_Builder->BuildMake = true;
					m_Builder->GradeType = 3;
					m_Builder->BuildPos = BuildRenderer->GetTransform().GetWorldPosition();

				}






			}
		}
	
		BuildCheck = false;
		PlusCheck = false;
		((UnitBase*)_Other->GetActor())->m_bClickCheck = true;

		





	}

	BuildRenderer->GetColorData().MulColor = { 1.f,0.f,0.f,0.5f };


	return false;
}

void MainMouse::ClickReset()
{


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
