

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UpgradeA;
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
	void Update(float _DeltaTime);
	void End() {}

private:
	GameEngineCollision* Col_ProUpgrade;
	GameEngineCollision* Col_TerUpgrade;
	GameEngineCollision* Col_ZergUpgrade;

	UpgradeA* m_UpC;


	bool Col_Pro(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Ter(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool Col_Zerg(GameEngineCollision* _This, GameEngineCollision* _Other);
public:
	void SetUpC(UpgradeA* UpC)
	{
		m_UpC = UpC;
	}


};

