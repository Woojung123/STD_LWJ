
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MiniMapUnit : public GameEngineActor
{
public:
	// constrcuter destructer
	MiniMapUnit();
	~MiniMapUnit();

	// delete Function
	MiniMapUnit(const MiniMapUnit& _Other) = delete;
	MiniMapUnit(MiniMapUnit&& _Other) noexcept = delete;
	MiniMapUnit& operator=(const MiniMapUnit& _Other) = delete;
	MiniMapUnit& operator=(MiniMapUnit&& _Other) noexcept = delete;
public:
	float4 UnitPos;
	GameEngineUIRenderer* Renderer;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
private:

};


