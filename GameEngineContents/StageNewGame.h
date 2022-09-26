
#pragma once
#include <GameEngineCore/GameEngineLevel.h>

// Ό³Έν :
class StageNewGame : public GameEngineLevel
{
public:
	// constrcuter destructer
	StageNewGame();
	~StageNewGame();

	// delete Function
	StageNewGame(const StageNewGame& _Other) = delete;
	StageNewGame(StageNewGame&& _Other) noexcept = delete;
	StageNewGame& operator=(const StageNewGame& _Other) = delete;
	StageNewGame& operator=(StageNewGame&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;

private:

};

