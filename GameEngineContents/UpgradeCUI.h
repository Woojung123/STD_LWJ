
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeC;
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
	void Update(float _DeltaTime);
	void End() {}

private:
	GameEngineCollision* Col_ProUpgrade;
	GameEngineCollision* Col_TerUpgrade;
	GameEngineCollision* Col_ZergUpgrade;
	GameEngineSoundPlayer SoundPlayer;
	UpgradeC* m_UpC;


	bool Col_Pro(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Ter(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Zerg(GameEngineCollision* _This, GameEngineCollision* _Other);
public:
	void SetUpC(UpgradeC* UpC)
	{
		m_UpC = UpC;
	}

};

