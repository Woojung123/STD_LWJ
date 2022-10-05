
#include "PreCompile.h"
#include "StageNewGame.h"
#include "WaveTest.h"

#include "Enums.h"


StageNewGame::StageNewGame()
{
}

StageNewGame::~StageNewGame()
{
}


void StageNewGame::Start()
{

	if (false == GameEngineInput::GetInst()->IsKey("LevelBack"))
	{
		GameEngineInput::GetInst()->CreateKey("LevelBack", 'V');
	}



	//{
	//	WaveTest* TestUni = CreateActor<WaveTest>(OBJECTORDER::TileMap);
	//}

}

void StageNewGame::Update(float _DeltaTime)
{
	if (true == GameEngineInput::GetInst()->IsDown("LevelBack"))
	{
		GEngine::ChangeLevel("Title");
	}
}

void StageNewGame::End()
{
}