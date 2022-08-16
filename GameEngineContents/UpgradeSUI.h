
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeSUI : public GameEngineActor
{
public:
	// constrcuter destructer
	UpgradeSUI();
	~UpgradeSUI();

	// delete Function
	UpgradeSUI(const UpgradeSUI& _Other) = delete;
	UpgradeSUI(UpgradeSUI&& _Other) noexcept = delete;
	UpgradeSUI& operator=(const UpgradeSUI& _Other) = delete;
	UpgradeSUI& operator=(UpgradeSUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

