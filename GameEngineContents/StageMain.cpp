

#include "PreCompile.h"
#include "StageMain.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineCameraActor.h>
#include <GameEngineBase/GameEngineInput.h>

#include "MainMap.h"
#include "StageMainCamera.h"
#include "TestUnit.h"
#include "Overload.h"
#include "UltraMon.h"
#include "DivaolerMon.h"
#include "corsairMon.h"
#include "ScoutMon.h"

#include "GhostC.h"
#include "MarinC.h"
#include "ZealotC.h"
#include "CorsairC.h"
#include "HydraC.h"
#include "ZerglingC.h"
#include "GardianC.h"
#include "HighT.h"
#include "CannonB.h"
#include "UltraC.h"
#include "SunkenC.h"
#include "DarkTB.h"
#include "ArbitorB.h"
#include "MutalA.h"
#include "Arcon.h"
#include "River.h"
#include "Carrier.h"
#include "GhostS.h"
#include "DroneS.h"
#include "ProbeS.h"
#include "HydraS.h"

#include "Tileobject.h"
#include "UIMouse.h"
#include "HPUnit.h"




#include "Builder.h"


#include "UpgradeC.h"
#include "UpgradeB.h"
#include "UpgradeA.h"
#include "UpgradeS.h"




#include "MainMouse.h"
#include "TestUI.h"
#include "MiniMap.h"



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

	BgmPlayer = GameEngineSound::SoundPlayControl("MainSound.MP3",true);
	BgmPlayer.PlaySpeed(1.f);
	BgmPlayer.Volume(0.1f);
	


	if (false == GameEngineInput::GetInst()->IsKey("FreeCameaOnOff"))
	{
		GameEngineInput::GetInst()->CreateKey("FreeCameaOnOff", 'O');
	}





	{
		TestUI* NewPlayer = CreateActor<TestUI>(OBJECTORDER::UI);
	}

	{
		MiniMap* NewPlayer = CreateActor<MiniMap>(OBJECTORDER::UI);
	}
	

		UIMouse* C_UIMouse = CreateActor<UIMouse>(OBJECTORDER::UI);




	
	
	MainMouse* MaMouse = CreateActor<MainMouse>(OBJECTORDER::Mouse);
	

	
	Builder* mBuilder = CreateActor<Builder>(OBJECTORDER::Player);
	mBuilder->GetTransform().SetWorldPosition({ -1017.f,336.f,0.f });
	mBuilder->m_MainMouse = MaMouse;
	mBuilder->m_Type = UNITTYPE::Builder;
	MaMouse->m_Builder = mBuilder;
	
	MapPoint MapP;







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
	
	
	
	
	


	MainMap* NewMainMap;
	{
		NewMainMap = CreateActor<MainMap>(OBJECTORDER::BackGround);
	}


	StageMainCamera* NewMainCamera;

	{
		NewMainCamera = CreateActor<StageMainCamera>(OBJECTORDER::Camera);
	}



	

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








	//유닛

	//{
	//	TestUnit* TestUni = CreateActor<TestUnit>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });
	//}
	//
	//{
	//	GhostC* TestUni = CreateActor<GhostC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -990.f,370.f,0.f });
	//}

	//{
	//	MarinC* TestUni = CreateActor<MarinC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -990.f,310.f,0.f });
	//}

	//{
	//	ZealotC* TestUni = CreateActor<ZealotC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1050.f,310.f,0.f });
	//}

	//{
	//	CorsairC* TestUni = CreateActor<CorsairC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1050.f,190.f,0.f });
	//}


	//{
	//	HydraC* TestUni = CreateActor<HydraC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -990.f,190.f,0.f });
	//}


	//{
	//	ZerglingC* TestUni = CreateActor<ZerglingC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -870.f,370.f,0.f });
	//}

	//{
	//	GardianC* TestUni = CreateActor<GardianC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -870.f,310.f,0.f });
	//}
	//
	//
	//{
	//	HighT* TestUni = CreateActor<HighT>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -810.f,310.f,0.f });
	//}


	//{
	//	CannonB* TestUni = CreateActor<CannonB>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1170.f,370.f,0.f });
	//}

	//{
	//	UltraC* TestUni = CreateActor<UltraC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1170.f,310.f,0.f });
	//}

	//{
	//	SunkenC* TestUni = CreateActor<SunkenC>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1230.f,310.f,0.f });
	//}

	//{
	//	DarkTB* TestUni = CreateActor<DarkTB>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1230.f,370.f,0.f });
	//}

	//
	//{
	//	ArbitorB* TestUni = CreateActor<ArbitorB>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1290.f,370.f,0.f });
	//}



	//{
	//	MutalA* TestUni = CreateActor<MutalA>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -1290.f,310.f,0.f });
	//}


	//
	//{
	//	Arcon* TestUni = CreateActor<Arcon>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -810.f,370.f,0.f });
	//}


	//{
	//	River* TestUni = CreateActor<River>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -750.f,370.f,0.f });
	//}

	//{
	//	Carrier* TestUni = CreateActor<Carrier>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -750.f,310.f,0.f });
	//}

	//{
	//	GhostS* TestUni = CreateActor<GhostS>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -810.f,190.f,0.f });
	//}


	//{
	//	DroneS* TestUni = CreateActor<DroneS>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -750.f,190.f,0.f });
	//}
	//

	//{
	//	ProbeS* TestUni = CreateActor<ProbeS>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -870.f,190.f,0.f });
	//}


	//{
	//	HydraS* TestUni = CreateActor<HydraS>(OBJECTORDER::Player);
	//	TestUni->GetTransform().SetWorldPosition({ -870.f,130.f,0.f });
	//}
	//








	{
		UpgradeC* TestUni = CreateActor<UpgradeC>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -508.f,617.f,0.f });
	}

	{
		UpgradeB* TestUni = CreateActor<UpgradeB>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -353.f,591.f,0.f });
	}

	{
		UpgradeA* TestUni = CreateActor<UpgradeA>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -508.f,505.f,0.f });
	}

	{
		UpgradeS* TestUni = CreateActor<UpgradeS>(OBJECTORDER::Player);
		TestUni->GetTransform().SetWorldPosition({ -372.f,445.f,0.f });
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

		HPRender[37]->GetTransform().SetWorldPosition({-550.f,70.f,0.f});
		HPRender[38]->GetTransform().SetWorldPosition({-500.f,70.f,0.f});
		HPRender[39]->GetTransform().SetWorldPosition({-450.f,70.f,0.f});
	}





}
void StageMain::Update(float _DeltaTime)
{

	if (Player_HP != Player_HPRen)
	{
		HPRender[Player_HPRen]->Death();
		Player_HPRen = Player_HP;
	}


	if (Player_HP < 0)
	{
		//게임 패배

		int A = 0;
	}

	if (GameEngineInput::GetInst()->IsDown("FreeCameaOnOff"))
	{
		// ;
		GetMainCameraActor()->FreeCameraModeOnOff();
	}


	GamePlayTime += _DeltaTime;
	
	
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
			TestUni->m_Info.m_Hp = 2000;
			TestUni->m_Info.m_MaxHp = 2000;
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
			TestUni->m_Info.m_Hp = 400;
			TestUni->m_Info.m_MaxHp = 400;
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
			TestUni->m_Info.m_Hp = 500;
			TestUni->m_Info.m_MaxHp = 500;
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
			TestUni->m_Info.m_Hp = 600;
			TestUni->m_Info.m_MaxHp = 600;
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
			TestUni->m_Info.m_Hp = 700;
			TestUni->m_Info.m_MaxHp = 700;
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
			TestUni->m_Info.m_Hp = 3000;
			TestUni->m_Info.m_MaxHp = 3000;
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
			TestUni->m_Info.m_Hp = 1500;
			TestUni->m_Info.m_MaxHp = 1500;
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
			TestUni->m_Info.m_Hp = 1650;
			TestUni->m_Info.m_MaxHp = 1650;
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
			TestUni->m_Info.m_Hp = 1800;
			TestUni->m_Info.m_MaxHp = 1800;
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
			TestUni->m_Info.m_Hp = 1950;
			TestUni->m_Info.m_MaxHp = 1950;
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
			TestUni->m_Info.m_Hp = 2100;
			TestUni->m_Info.m_MaxHp = 2100;
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
			TestUni->m_Info.m_Hp = 9000;
			TestUni->m_Info.m_MaxHp = 6000;
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
			TestUni->m_Info.m_Hp = 4000;
			TestUni->m_Info.m_MaxHp = 4000;
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
			TestUni->m_Info.m_Hp = 4200;
			TestUni->m_Info.m_MaxHp = 4200;
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
			TestUni->m_Info.m_Hp = 4400;
			TestUni->m_Info.m_MaxHp = 4400;
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
			TestUni->m_Info.m_Hp = 4600;
			TestUni->m_Info.m_MaxHp = 4600;
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
			TestUni->m_Info.m_Hp = 5000;
			TestUni->m_Info.m_MaxHp = 5000;
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
			TestUni->m_Info.m_Hp = 15000;
			TestUni->m_Info.m_MaxHp = 15000;
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
			TestUni->m_Info.m_Hp = 10000;
			TestUni->m_Info.m_MaxHp = 10000;
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
			TestUni->m_Info.m_Hp = 10500;
			TestUni->m_Info.m_MaxHp = 10500;
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
			TestUni->m_Info.m_Hp = 11000;
			TestUni->m_Info.m_MaxHp = 11000;
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
			TestUni->m_Info.m_Hp = 11500;
			TestUni->m_Info.m_MaxHp = 11500;
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
			TestUni->m_Info.m_Hp = 12000;
			TestUni->m_Info.m_MaxHp = 12000;
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
			TestUni->m_Info.m_Hp = 30000;
			TestUni->m_Info.m_MaxHp = 30000;
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
			TestUni->m_Info.m_Hp = 50000;
			TestUni->m_Info.m_MaxHp = 50000;
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



