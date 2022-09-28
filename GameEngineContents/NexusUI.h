

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class Nexus;
class NexusUI : public GameEngineActor
{
public:
	// constrcuter destructer
	NexusUI();
	~NexusUI();

	// delete Function
	NexusUI(const NexusUI& _Other) = delete;
	NexusUI(NexusUI&& _Other) noexcept = delete;
	NexusUI& operator=(const NexusUI& _Other) = delete;
	NexusUI& operator=(NexusUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}



public:

	int MakeCount = 0;
	bool UpCheck  = false;
	float UpTime = 0.f;
	float UpPercent = 0.f;


	GameEngineCollision* Col_ProUpgrade;

	GameEngineSoundPlayer SoundPlayer;
	GameEngineUIRenderer* StatusRenderer;
	GameEngineUIRenderer* ProGressMainRenderer;
	GameEngineUIRenderer* ProGressUpRenderer;

	GameEngineUIRenderer* ProbeRender[5];

	Nexus* m_UpC;


	bool Col_Pro(GameEngineCollision* _This, GameEngineCollision* _Other);

};

