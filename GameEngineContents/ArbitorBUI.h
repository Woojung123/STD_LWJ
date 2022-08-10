

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class ArbitorBUI : public GameEngineActor
{
public:
	// constrcuter destructer
	ArbitorBUI();
	~ArbitorBUI();

	// delete Function
	ArbitorBUI(const ArbitorBUI& _Other) = delete;
	ArbitorBUI(ArbitorBUI&& _Other) noexcept = delete;
	ArbitorBUI& operator=(const ArbitorBUI& _Other) = delete;
	ArbitorBUI& operator=(ArbitorBUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

