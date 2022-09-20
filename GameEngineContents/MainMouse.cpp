

#include "PreCompile.h"
#include "MainMouse.h"
#include "StageMainCamera.h"
#include"UnitBase.h"
#include "Builder.h"
#include "DragUI.h"
#include "BuildImage.h"

#include "StageMain.h"
#include "MiniMapPlayer.h"




MainMouse::MainMouse()	:
	m_DragStartPos({})
	, m_DragEndPos({})
	, StartDragCheck(false)
	,BuildCheck(false)
	,BuildColorCheck(false)
	,BuildRenderer(nullptr)
	,Collision(nullptr)
	,DragCollision(nullptr)
	,DragRenderer(nullptr)
	,m_Builder(nullptr)
	,PlusCheck(false)
	,Renderer(nullptr)
	, m_DragUI(nullptr)
	, m_Stage(0)
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
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("PlayerMonMini.png");
		Renderer->ScaleToTexture();

	}


	{
		BuildRenderer = CreateComponent<GameEngineTextureRenderer>();
		BuildRenderer->SetTexture("PylonBuild.png");
		BuildRenderer->ScaleToTexture();

	}

	{
		DragRenderer = CreateComponent<GameEngineTextureRenderer>();
		DragRenderer->SetTexture("Mouse.png");
		DragRenderer->ScaleToTexture();
		DragRenderer->GetPixelData().MulColor.a = 0.5f;
		DragRenderer->Off();
	}
	{
		DragCollision = CreateComponent<GameEngineCollision>();
		DragCollision->GetTransform().SetLocalScale({ 1.f, 1.f, 1.0f });
		DragCollision->ChangeOrder(OBJECTORDER::MouseDrag);
		DragCollision->Off();
	}

	
	GameEngineInput::GetInst()->CreateKey("LeftClick", VK_LBUTTON);
	GameEngineInput::GetInst()->CreateKey("BuilderClick", '1');



	m_DragUI = GetLevel()->CreateActor<DragUI>(OBJECTORDER::UI);
	m_DragUI->m_Mouse = this;


}



void MainMouse::Update(float _DeltaTime)
{
	if (vec_DragUnit.size() == 1)
	{
		auto	iter = vec_DragUnit.begin();
	

		(*iter)->m_bClickCheck = true;
	}
	else if (vec_DragUnit.size() > 1)
	{
		DragReset();
		m_DragUI->On();
		m_DragUI->DragSize = (int)vec_DragUnit.size();
	}
	else
	{
		m_DragUI->Off();
		m_DragUI->DragSize = 0;
	}


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


	if (!StartDragCheck)
	{

		m_DragStartPos = WorldPos;

	}

	if (true == GameEngineInput::GetInst()->IsDown("LeftClick"))
	{

		StartDragCheck = true;

	}


	if (true == GameEngineInput::GetInst()->IsPress("LeftClick"))
	{


		m_DragEndPos = WorldPos;

		float4 DumPos = {};

		float4 DragScale = {};
		float4 DragPos = {};

		if (m_DragEndPos.x != m_DragStartPos.x || m_DragEndPos.y != m_DragStartPos.y)
		{
			DragScale.x = m_DragEndPos.x - m_DragStartPos.x;
			DragScale.y = m_DragStartPos.y - m_DragEndPos.y;

			DragPos.x = m_DragStartPos.x + (DragScale.x/2);
			DragPos.y = m_DragStartPos.y - (DragScale.y/2);
			DragPos.z = -400.f;
			DragRenderer->GetTransform().SetWorldScale(DragScale);
			DragRenderer->GetTransform().SetWorldPosition(DragPos);

			DragCollision->GetTransform().SetWorldScale(DragScale);
			DragCollision->GetTransform().SetWorldPosition(DragPos);


		

			DragRenderer->On();
			DragCollision->On();

		}
		


	}


	if (true == GameEngineInput::GetInst()->IsFree("LeftClick"))
	{
	//	ClickReset();



		DragCollision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Player, CollisionType::CT_OBB2D,
			std::bind(&MainMouse::MDragCollision, this, std::placeholders::_1, std::placeholders::_2)
		);


	


		DragRenderer->Off();
		DragCollision->Off();

	
		StartDragCheck = false;
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
		BuildRenderer->GetPixelData().MulColor = { 1.f,0.f,0.f,0.5f };

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
		BuildRenderer->GetPixelData().MulColor = { 0.f,1.f,0.f,0.5f };
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


	if (((UnitBase*)(_Other->GetActor()))->m_Type != UNITTYPE::Builder)
	{
		BuildRenderer->GetPixelData().MulColor = { 1.f,0.f,0.f,0.5f };
	}
	
	


	return true;
}

bool MainMouse::MDragCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	UNITTYPE _type = ((UnitBase*)_Other->GetActor())->m_Type;

	
	if(vec_DragUnit.size() < 12)
	{
		vec_DragUnit.push_back(((UnitBase*)_Other->GetActor()));
		((UnitBase*)_Other->GetActor())->m_bDragCheck = true;
	}

	


	return false;
}


void MainMouse::DragReset()
{

	{
		std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Player);


		auto	iter = Group.begin();
		auto	iterEnd = Group.end();

		for (; iter != iterEnd; ++iter)
		{
			((UnitBase*)(*iter))->m_bClickCheck = false;
		//	((UnitBase*)(*iter))->m_bDragCheck = false;
		}


	}


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
			((UnitBase*)(*iter))->m_bDragCheck = false;
		}


	}

	vec_DragUnit.clear();


}
