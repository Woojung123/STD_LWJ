#pragma once



#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class ProbeS;
class GameEngineTextureRenderer;
class TrailBullet : public UnitBase
{
public:
	// constrcuter destructer
	TrailBullet();
	~TrailBullet();

	// delete Function
	TrailBullet(const TrailBullet& _Other) = delete;
	TrailBullet(TrailBullet&& _Other) noexcept = delete;
	TrailBullet& operator=(const TrailBullet& _Other) = delete;
	TrailBullet& operator=(TrailBullet&& _Other) noexcept = delete;
	bool MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

	float4 Color;

public:
	ProbeS* m_Probe;
	float Speed;
	bool	DamCheck;
	float4 m_Dir;
	GameEngineActor* TarGet;

private:
	float4 Pos;
	float4 StartPostion;
	float4 DirPower;

public:
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

