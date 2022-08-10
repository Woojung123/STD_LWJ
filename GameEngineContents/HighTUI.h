
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class HighTUI : public GameEngineActor
{
public:
	// constrcuter destructer
	HighTUI();
	~HighTUI();

	// delete Function
	HighTUI(const HighTUI& _Other) = delete;
	HighTUI(HighTUI&& _Other) noexcept = delete;
	HighTUI& operator=(const HighTUI& _Other) = delete;
	HighTUI& operator=(HighTUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

