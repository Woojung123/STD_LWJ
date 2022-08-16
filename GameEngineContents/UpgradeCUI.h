
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	UpgradeCUI();
	~UpgradeCUI();

	// delete Function
	UpgradeCUI(const UpgradeCUI& _Other) = delete;
	UpgradeCUI(UpgradeCUI&& _Other) noexcept = delete;
	UpgradeCUI& operator=(const UpgradeCUI& _Other) = delete;
	UpgradeCUI& operator=(UpgradeCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

