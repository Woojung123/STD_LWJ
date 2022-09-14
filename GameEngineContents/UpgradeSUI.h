
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeS;
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
	void Update(float _DeltaTime);
	void End() {}



private:
	GameEngineCollision* Col_ProUpgrade;
	GameEngineCollision* Col_TerUpgrade;
	GameEngineCollision* Col_ZergUpgrade;
	GameEngineSoundPlayer SoundPlayer;
	UpgradeS* m_UpC;


	bool Col_Pro(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Ter(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Zerg(GameEngineCollision* _This, GameEngineCollision* _Other);
public:
	void SetUpC(UpgradeS* UpC)
	{
		m_UpC = UpC;
	}
};

