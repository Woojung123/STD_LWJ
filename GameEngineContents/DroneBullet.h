
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class DroneBullet : public UnitBase
{
public:
	// constrcuter destructer
	DroneBullet();
	~DroneBullet();

	// delete Function
	DroneBullet(const DroneBullet& _Other) = delete;
	DroneBullet(DroneBullet&& _Other) noexcept = delete;
	DroneBullet& operator=(const DroneBullet& _Other) = delete;
	DroneBullet& operator=(DroneBullet&& _Other) noexcept = delete;

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

