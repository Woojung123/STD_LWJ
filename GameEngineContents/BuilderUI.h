
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class StageMain;
class Builder;
class BuilderUI : public GameEngineActor
{
public:
	// constrcuter destructer
	BuilderUI();
	~BuilderUI();

	// delete Function
	BuilderUI(const BuilderUI& _Other) = delete;
	BuilderUI(BuilderUI&& _Other) noexcept = delete;
	BuilderUI& operator=(const BuilderUI& _Other) = delete;
	BuilderUI& operator=(BuilderUI&& _Other) noexcept = delete;
	StageMain* m_Stage;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

public:
	Builder* m_Builder;
	GameEngineCollision* CollisionMake;
	GameEngineCollision* CollisionBuild;
	GameEngineCollision* CollisionSell;
	bool BuildCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool MakeCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool SellCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

};

