
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class SwarmBullet : public UnitBase
{
public:
	// constrcuter destructer
	SwarmBullet();
	~SwarmBullet();

	// delete Function
	SwarmBullet(const SwarmBullet& _Other) = delete;
	SwarmBullet(SwarmBullet&& _Other) noexcept = delete;
	SwarmBullet& operator=(const SwarmBullet& _Other) = delete;
	SwarmBullet& operator=(SwarmBullet&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;
	GameEngineActor* TarGet;
public:
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

