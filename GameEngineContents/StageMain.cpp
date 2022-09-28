

#include "PreCompile.h"
#include "StageMain.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

#include "MainMap.h"
#include "DarkMap.h"
#include "DarkTile.h"


#include "StageMainCamera.h"
#include "TestUnit.h"
#include "Overload.h"
#include "UltraMon.h"
#include "DivaolerMon.h"
#include "corsairMon.h"
#include "ScoutMon.h"


#include "Tileobject.h"
#include "UIMouse.h"
#include "HPUnit.h"

#include "Intercept.h"




#include "Builder.h"


#include "UpgradeC.h"
#include "UpgradeB.h"
#include "UpgradeA.h"
#include "UpgradeS.h"
#include "PlayNormal.h"
#include "Nexus.h"




#include "MainMouse.h"
#include "TestUI.h"
#include "MiniMap.h"

#include "HellperWindow.h"

StageMain::StageMain() :
	StartCheck(false),
	StartTime(1.f),//10
	GamePlayTime(0.f),
	MonCount(0),
	MonMax(20),//20
	MonTimeMax(0.5f),
	MonTime(0.f),
	StageCount(1)
{
}

StageMain::~StageMain()
{
}

void StageMain::Start()
{

	HellperWindowGUI = GameEngineGUI::CreateGUIWindow<HellperWindow>("MetaAnimationGUI", this);
	HellperWindowGUI->m_MainSt = this;

	BgmPlayer = GameEngineSound::SoundPlayControl("MainSound.MP3",true);
	BgmPlayer.PlaySpeed(1.f);
	BgmPlayer.Volume(0.5f);
	


	if (false == GameEngineInput::GetInst()->IsKey("FreeCameaOnOff"))
	{
		GameEngineInput::GetInst()->CreateKey("FreeCameaOnOff", 'O');
	}

	GameEngineInput::GetInst()->CreateKey("GameFinish", '5');
	GameEngineInput::GetInst()->CreateKey("DarkMapD", '6');



	{
		TestUI* NewPlayer = CreateActor<TestUI>(OBJECTORDER::UI);
		NewPlayer->m_Stage = this;
	}


	

	



		UIMouse* C_UIMouse = CreateActor<UIMouse>(OBJECTORDER::UI);




	
	
	MainMouse* MaMouse = CreateActor<MainMouse>(OBJECTORDER::Mouse);
	MaMouse->m_Stage = this;

	
	Builder* mBuilder = CreateActor<Builder>(OBJECTORDER::Player);
	mBuilder->GetTransform().SetWorldPosition({ 1022.f,-414.f,0.f });//1022.f,-414.f// -1017.f,336.f
	mBuilder->m_MainMouse = MaMouse;
	mBuilder->m_Type = UNITTYPE::Builder;
	MaMouse->m_Builder = mBuilder;
	mBuilder->m_Stage = this;
	
	MapPoint MapP;

	{
		MiniMap* NewPlayer = CreateActor<MiniMap>(OBJECTORDER::UI);
		NewPlayer->m_Bulder = mBuilder;


	}


	


	MapP.TurnPoint = float4(-1348.f, 424.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-682.f, 424.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-682.f, 604.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-924.f, 604.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-924.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-681.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-681.f, 245.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1348.f, 245.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1348.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1105.f, 62.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);

	MapP.TurnPoint = float4(-1105.f, 633.f, 1.f, 0.f);
	CheckPoint.push_back(MapP);
	
	
	
	
	StageMainCamera* NewMainCamera;

	{
		NewMainCamera = CreateActor<StageMainCamera>(OBJECTORDER::Camera);
		NewMainCamera->GetTransform().SetWorldPosition({ 1022.f,-414.f,0.f });
	}

	

	MainMap* NewMainMap;
	{
		NewMainMap = CreateActor<MainMap>(OBJECTORDER::BackGround);
	}

	
	{
		NewDarkMap = CreateActor<DarkMap>(OBJECTORDER::BackGround);
		NewDarkMap->m_Bulder = mBuilder;
		NewDarkMap->MainStage = this;
		NewDarkMap->M_Camera = NewMainCamera;
	}
	


	/*{
		

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
			{

				DTilemap[i][j] = CreateActor<DarkTile>(OBJECTORDER::TileMap);
				DTilemap[i][j]->GetTransform().SetWorldPosition({   (( - 1400.f) + (float)(i * 100.f))   ,   ((700.f) - (float)(j * 110.f))   });
				DTilemap[i][j]->M_Camera = NewMainCamera;
			}
		}
	


	}*/
	




	

	//중간
	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1046.f,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -986.f,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1046.f,301.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -986.f,301.f,0.f });
	}


	//아래중간

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1046.f,181.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -986.f,181.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1046.f,121.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -986.f,121.f,0.f });
	}




	//위에중간

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1046.f,541.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -986.f,541.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1046.f,481.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -986.f,481.f,0.f });
	}








	// 오른쪽 중간
	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -866.f,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -806.f,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -866.f,301.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -806.f,301.f,0.f });
	}


	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -746.f,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -746.f,301.f,0.f });
	}




	//위에오른쪽

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -866.f,541.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -806.f,541.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -746.f,541.f,0.f });
	}


	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -866.f,481.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -806.f,481.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -746.f,481.f,0.f });
	}








	//아래 오른쪽

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -866.f,181.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -806.f,181.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -746.f,181.f,0.f });
	}



	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -866.f,121.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -806.f,121.f,0.f });
	}


	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -746.f,121.f,0.f });
	}
















	//왼쪽 중간ㄱ

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1226.f,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1286.f,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1346,361.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1166.f,361.f,0.f });
	}



	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1226.f,301.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1286.f,301.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1346,301.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1166.f,301.f,0.f });
	}



	//아래중간

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1286.f,181.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1226.f,181.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1166.f,181.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1226.f,121.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1286.f,121.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1166.f,121.f,0.f });
	}


	//위에중간

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1286.f,541.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1166.f,541.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1226.f,541.f,0.f });
	}


	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1286.f,481.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1166.f,481.f,0.f });
	}

	{
		Tileobject* TestUni = CreateActor<Tileobject>(OBJECTORDER::TileMap);
		TestUni->GetTransform().SetWorldPosition({ -1226.f,481.f,0.f });
	}





	{
		UpgradeC* TestUni = CreateActor<UpgradeC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -508.f,617.f,0.f });
		TestUni->m_MainStage = this;
	}

	{
		UpgradeB* TestUni = CreateActor<UpgradeB>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -353.f,591.f,0.f });
		TestUni->m_MainStage = this;
	}

	{
		UpgradeA* TestUni = CreateActor<UpgradeA>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -508.f,505.f,0.f });
		TestUni->m_MainStage = this;
	}

	{
		UpgradeS* TestUni = CreateActor<UpgradeS>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -372.f,445.f,0.f });
		TestUni->m_MainStage = this;
	}

	{
		Nexus* TestUni = CreateActor<Nexus>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -412.f,-240.f,0.f });
		TestUni->m_MainStage = this;
	}






	//NewMainCamera, mBuilder
	{
		Bicon1 = CreateActor<PlayNormal>(OBJECTORDER::Player);
		Bicon1->GetTransform().SetWorldPosition({ 1012.f,-224.f,0.f });
		Bicon1->BiconType = 0;
		Bicon1->m_Builder = mBuilder;
		Bicon1->m_STMain = this;
		Bicon1->m_MainCamera = NewMainCamera;

	}

	{
		Bicon2 = CreateActor<PlayNormal>(OBJECTORDER::Player);
		Bicon2->GetTransform().SetWorldPosition({ 842.f,-400.f,0.f });
		Bicon2->BiconType = 1;
		Bicon2->m_Builder = mBuilder;
		Bicon2->m_STMain = this;
		Bicon2->m_MainCamera = NewMainCamera;
	}

	{
		Bicon3 = CreateActor<PlayNormal>(OBJECTORDER::Player);
		Bicon3->GetTransform().SetWorldPosition({ 1209.f,-400.f,0.f });
		Bicon3->BiconType = 2;
		Bicon3->m_Builder = mBuilder;
		Bicon3->m_STMain = this;
		Bicon3->m_MainCamera = NewMainCamera;




	}
	
	//GameEngineStatusWindow::AddDebugRenderTarget("BackBuffer", GameEngineDevice::GetBackBuffer());
	//GameEngineStatusWindow::AddDebugRenderTarget("MainCamera", GetMainCamera()->GetCameraRenderTarget());
	//GameEngineStatusWindow::AddDebugRenderTarget("UICamera", GetUICamera()->GetCameraRenderTarget());
	
	



	{
		for (int i = 0; i <= 39; ++i)
		{

			HPUnit* HPUni = CreateActor<HPUnit>(OBJECTORDER::Player);

			HPRender[i] = HPUni;
			HPRender[i]->GetTransform().SetWorldPosition({ 0.f + i,0.f,0.f });

		}
		
		int count = 0;


		for (int i = 0; i <= 5; ++i)
		{
			for (int j = 0; j <= 5; ++j)
			{

				HPRender[count]->GetTransform().SetWorldPosition({ -550.f + i * 50.f ,100.f + j * 30.f ,0.f });

				++count;
			}
		}

		HPRender[36]->GetTransform().SetWorldPosition({ -400.f,70.f,0.f });
		HPRender[37]->GetTransform().SetWorldPosition({-550.f,70.f,0.f});
		HPRender[38]->GetTransform().SetWorldPosition({-500.f,70.f,0.f});
		HPRender[39]->GetTransform().SetWorldPosition({-450.f,70.f,0.f});
	}





}
void StageMain::Update(float _DeltaTime)
{

	if (Player_HP != Player_HPRen)
	{
		if (Player_HPRen <= 0)
			Player_HPRen = 0;


		HPRender[Player_HPRen]->Off();
		Player_HPRen = Player_HP;
	}


	if (Player_HP < 0)
	{
		//게임 패배
		StartCheck = false;
		StageCount = 30;
		GameFinishBool = true;
		
	}

	if (GameEngineInput::GetInst()->IsDown("FreeCameaOnOff"))
	{
		// ;
		GetMainCameraActor()->FreeCameraModeOnOff();
	}

	if (GameEngineInput::GetInst()->IsDown("GameFinish"))
	{
		if (GameFinishBool)
		{
			GameFinishBool = !GameFinishBool;

		}
		else
		{
			GameFinishBool = !GameFinishBool;
		}
			
	}


	if (GameEngineInput::GetInst()->IsDown("DarkMapD"))
	{
		NewDarkMap->Death();

	}


	

	if (GameStartB)
	{
		GamePlayTime += _DeltaTime;

	}
	
	
	
	//1.몬스터가 다 죽었을때
	//몬스터 리스트.사이즈 = 0일때 


	if (!StartCheck)
	{

	
		if (GamePlayTime >= StartTime)//10초후 시작
		{
			StartCheck = true;
		}


	}
	else
	{
		if (StageCount == 1)
		{
			Stage1(_DeltaTime);

		}
		else if (StageCount == 2)
		{

			Stage2(_DeltaTime);
		}
		else if (StageCount == 3)
		{

			Stage3(_DeltaTime);
		}
		else if (StageCount == 4)
		{

			Stage4(_DeltaTime);
		}
		else if (StageCount == 5)
		{

			Stage5(_DeltaTime);
		}
		else if (StageCount == 6)
		{

			Stage6(_DeltaTime);
		}
		else if (StageCount == 7)
		{

			Stage7(_DeltaTime);
		}
		else if (StageCount == 8)
		{

			Stage8(_DeltaTime);
		}
		else if (StageCount == 9)
		{

			Stage9(_DeltaTime);
		}
		else if (StageCount == 10)
		{

			Stage10(_DeltaTime);
		}
		else if (StageCount == 11)
		{

			Stage11(_DeltaTime);
		}
		else if (StageCount == 12)
		{

			Stage12(_DeltaTime);
		}
		else if (StageCount == 13)
		{

			Stage13(_DeltaTime);
		}
		else if (StageCount == 14)
		{

			Stage14(_DeltaTime);
		}
		else if (StageCount == 15)
		{

			Stage15(_DeltaTime);
		}
		else if (StageCount == 16)
		{

			Stage16(_DeltaTime);
		}
		else if (StageCount == 17)
		{

			Stage17(_DeltaTime);
		}
		else if (StageCount == 18)
		{

			Stage18(_DeltaTime);
		}
		else if (StageCount == 19)
		{

			Stage19(_DeltaTime);
		}
		else if (StageCount == 20)
		{

			Stage20(_DeltaTime);
		}
		else if (StageCount == 21)
		{

			Stage21(_DeltaTime);
		}
		else if (StageCount == 22)
		{

			Stage22(_DeltaTime);
		}
		else if (StageCount == 23)
		{

			Stage23(_DeltaTime);
		}
		else if (StageCount == 24)
		{

			Stage24(_DeltaTime);
		}
		else if (StageCount == 25)
		{

			Stage25(_DeltaTime);
		}


	}
	


}
void StageMain::End() 
{


}


void StageMain::Stage1(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{


				Bicon1->Death();
				Bicon2->Death();
				Bicon3->Death();


				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			corsairMon* TestUni = CreateActor<corsairMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 50 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 50 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;

			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;

	}

}
void StageMain::Stage2(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			ScoutMon* TestUni = CreateActor<ScoutMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 400 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 400 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage3(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			DivaolerMon* TestUni = CreateActor<DivaolerMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 500 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 500 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage4(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			UltraMon* TestUni = CreateActor<UltraMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 600 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 600 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}


}

void StageMain::Stage5(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			Overload* TestUni = CreateActor<Overload>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 700 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 700 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}


//보스
void StageMain::Stage6(float _DeltaTime)
{
	MonTime += _DeltaTime;


	int BosMax = 1;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == BosMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 500;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			corsairMon* TestUni = CreateActor<corsairMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 3000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 3000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}
void StageMain::Stage7(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			corsairMon* TestUni = CreateActor<corsairMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 1500 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 1500 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage8(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			ScoutMon* TestUni = CreateActor<ScoutMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 1650 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 1650 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage9(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			DivaolerMon* TestUni = CreateActor<DivaolerMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 1800 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 1800 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage10(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			UltraMon* TestUni = CreateActor<UltraMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 1950 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 1950 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}

}
void StageMain::Stage11(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			Overload* TestUni = CreateActor<Overload>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 2100 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 2100 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}


//보스2
void StageMain::Stage12(float _DeltaTime)
{
	MonTime += _DeltaTime;


	int BosMax = 1;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == BosMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 500;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			ScoutMon* TestUni = CreateActor<ScoutMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 9000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 6000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}




void StageMain::Stage13(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			corsairMon* TestUni = CreateActor<corsairMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 4000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 4000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage14(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			ScoutMon* TestUni = CreateActor<ScoutMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 4200 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 4200 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage15(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			DivaolerMon* TestUni = CreateActor<DivaolerMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 4400 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 4400 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage16(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			UltraMon* TestUni = CreateActor<UltraMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 4600 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 4600 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}

}
void StageMain::Stage17(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			Overload* TestUni = CreateActor<Overload>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 5000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 5000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}


//보스 3
void StageMain::Stage18(float _DeltaTime)
{
	MonTime += _DeltaTime;


	int BosMax = 1;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == BosMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 500;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			DivaolerMon* TestUni = CreateActor<DivaolerMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 15000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 15000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}




void StageMain::Stage19(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			corsairMon* TestUni = CreateActor<corsairMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 10000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 10000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage20(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			ScoutMon* TestUni = CreateActor<ScoutMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 10500 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 10500 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage21(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			DivaolerMon* TestUni = CreateActor<DivaolerMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 11000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 11000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}


		++MonCount;



	}
}
void StageMain::Stage22(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			UltraMon* TestUni = CreateActor<UltraMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 11500 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 11500 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}

}


void StageMain::Stage23(float _DeltaTime)
{
	MonTime += _DeltaTime;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == MonMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 250;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			Overload* TestUni = CreateActor<Overload>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 12000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 12000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}

//보스4
void StageMain::Stage24(float _DeltaTime)
{
	MonTime += _DeltaTime;


	int BosMax = 1;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == BosMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				Player_Gold += 500;
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			UltraMon* TestUni = CreateActor<UltraMon>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 30000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 30000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}



void StageMain::Stage25(float _DeltaTime)
{
	MonTime += _DeltaTime;


	int BosMax = 1;

	if (MonTime >= MonTimeMax)
	{

		if (MonCount == BosMax)
		{


			if (GetGroup(OBJECTORDER::Monster).size() == 0)
			{
				MonTime = 0.f;
				GamePlayTime = 0.f;
				MonCount = 0;
				++StageCount;
				StartCheck = false;
			}

			return;
		}
		MonTime -= MonTimeMax;

		{
			Overload* TestUni = CreateActor<Overload>(OBJECTORDER::Monster);
			TestUni->m_Info.m_Hp = 50000 * MonHpLevel;
			TestUni->m_Info.m_MaxHp = 50000 * MonHpLevel;
			TestUni->m_Info.Gold = 8;
			TestUni->m_MainStage = this;
			auto	iter = CheckPoint.begin();
			auto	iterEnd = CheckPoint.end();

			for (; iter != iterEnd; ++iter)
			{
				TestUni->SetCheckPoinr(*iter);
			}

		}

		++MonCount;

	}
}



