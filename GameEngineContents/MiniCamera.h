
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MiniCamera : public GameEngineActor
{
public:
	// constrcuter destructer
	MiniCamera();
	~MiniCamera();

	// delete Function
	MiniCamera(const MiniCamera& _Other) = delete;
	MiniCamera(MiniCamera&& _Other) noexcept = delete;
	MiniCamera& operator=(const MiniCamera& _Other) = delete;
	MiniCamera& operator=(MiniCamera&& _Other) noexcept = delete;
public:
	float4 UnitPos;
	GameEngineUIRenderer* Renderer;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
private:

};


