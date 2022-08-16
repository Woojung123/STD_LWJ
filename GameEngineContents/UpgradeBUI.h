
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeBUI : public GameEngineActor
{
public:
	// constrcuter destructer
	UpgradeBUI();
	~UpgradeBUI();

	// delete Function
	UpgradeBUI(const UpgradeBUI& _Other) = delete;
	UpgradeBUI(UpgradeBUI&& _Other) noexcept = delete;
	UpgradeBUI& operator=(const UpgradeBUI& _Other) = delete;
	UpgradeBUI& operator=(UpgradeBUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

