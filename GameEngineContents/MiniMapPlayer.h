
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MiniMapPlayer : public GameEngineActor
{
public:
	// constrcuter destructer
	MiniMapPlayer();
	~MiniMapPlayer();

	// delete Function
	MiniMapPlayer(const MiniMapPlayer& _Other) = delete;
	MiniMapPlayer(MiniMapPlayer&& _Other) noexcept = delete;
	MiniMapPlayer& operator=(const MiniMapPlayer& _Other) = delete;
	MiniMapPlayer& operator=(MiniMapPlayer&& _Other) noexcept = delete;
public:
	float4 UnitPos;
	GameEngineUIRenderer* Renderer;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
private:

};


