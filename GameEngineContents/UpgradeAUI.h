

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeAUI : public GameEngineActor
{
public:
	// constrcuter destructer
	UpgradeAUI();
	~UpgradeAUI();

	// delete Function
	UpgradeAUI(const UpgradeAUI& _Other) = delete;
	UpgradeAUI(UpgradeAUI&& _Other) noexcept = delete;
	UpgradeAUI& operator=(const UpgradeAUI& _Other) = delete;
	UpgradeAUI& operator=(UpgradeAUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

