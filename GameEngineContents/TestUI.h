

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ???? :
class StageMain;
class TestUI : public GameEngineActor
{
public:
	// constrcuter destructer
	TestUI();
	~TestUI();

	// delete Function
	TestUI(const TestUI& _Other) = delete;
	TestUI(TestUI&& _Other) noexcept = delete;
	TestUI& operator=(const TestUI& _Other) = delete;
	TestUI& operator=(TestUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}


public : 

	GameEngineFontRenderer* FontAMission;
	GameEngineFontRenderer* FontBMission;
	GameEngineFontRenderer* FontCMission;


	GameEngineUIRenderer* MissionTerRender;
	GameEngineUIRenderer* MissionProRender;
	GameEngineUIRenderer* MissionZergRender;
	GameEngineUIRenderer* MissionAirRender;


	StageMain* m_Stage;
private:
	GameEngineFontRenderer* Font;


	GameEngineFontRenderer* VictoryFont;
	GameEngineUIRenderer* BaseEndingRenderer;
	GameEngineFontRenderer* OkFont;

};

