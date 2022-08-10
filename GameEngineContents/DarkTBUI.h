
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DarkTBUI : public GameEngineActor
{
public:
	// constrcuter destructer
	DarkTBUI();
	~DarkTBUI();

	// delete Function
	DarkTBUI(const DarkTBUI& _Other) = delete;
	DarkTBUI(DarkTBUI&& _Other) noexcept = delete;
	DarkTBUI& operator=(const DarkTBUI& _Other) = delete;
	DarkTBUI& operator=(DarkTBUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

