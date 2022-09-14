
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeB;
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
	void Update(float _DeltaTime);
	void End() {}

private:
	GameEngineCollision* Col_ProUpgrade;
	GameEngineCollision* Col_TerUpgrade;
	GameEngineCollision* Col_ZergUpgrade;
	GameEngineSoundPlayer SoundPlayer;
	UpgradeB* m_UpC;


	bool Col_Pro(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Ter(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Zerg(GameEngineCollision* _This, GameEngineCollision* _Other);
public:
	void SetUpC(UpgradeB* UpC)
	{
		m_UpC = UpC;
	}



};

