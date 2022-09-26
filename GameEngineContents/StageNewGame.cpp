
#include "PreCompile.h"
#include "StageNewGame.h"


#include "Enums.h"
//#include <GameEngineCore/GEngine.h>
//#include <GameEngineCore/GameEngineCameraActor.h>
//#include <GameEngineBase/GameEngineInput.h>

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