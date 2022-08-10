
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class DroneEffect : public UnitBase
{
public:
	// constrcuter destructer
	DroneEffect();
	~DroneEffect();

	// delete Function
	DroneEffect(const DroneEffect& _Other) = delete;
	DroneEffect(DroneEffect&& _Other) noexcept = delete;
	DroneEffect& operator=(const DroneEffect& _Other) = delete;
	DroneEffect& operator=(DroneEffect&& _Other) noexcept = delete;
	bool MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;

};
