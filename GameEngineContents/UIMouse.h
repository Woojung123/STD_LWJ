
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UIMouse : public GameEngineActor
{
public:
	// constrcuter destructer
	UIMouse();
	~UIMouse();

	// delete Function
	UIMouse(const UIMouse& _Other) = delete;
	UIMouse(UIMouse&& _Other) noexcept = delete;
	UIMouse& operator=(const UIMouse& _Other) = delete;
	UIMouse& operator=(UIMouse&& _Other) noexcept = delete;
public:
	float4 UnitPos;
	GameEngineUIRenderer* Renderer;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
private:

};


