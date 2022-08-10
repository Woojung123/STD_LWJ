

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class SwarmEffect : public UnitBase
{
public:
	// constrcuter destructer
	SwarmEffect();
	~SwarmEffect();

	// delete Function
	SwarmEffect(const SwarmEffect& _Other) = delete;
	SwarmEffect(SwarmEffect&& _Other) noexcept = delete;
	SwarmEffect& operator=(const SwarmEffect& _Other) = delete;
	SwarmEffect& operator=(SwarmEffect&& _Other) noexcept = delete;


	bool MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	bool	collcheck;
	float	colTime;

	GameEngineTextureRenderer* Renderer;
	
	float4 Color;

private:
	float Speed;
	float4 m_Dir;

};
