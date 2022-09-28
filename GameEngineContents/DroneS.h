
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class DroneSUI;
class SwarmBullet;
class GameEngineTextureRenderer;
class DroneS : public UnitBase
{
public:
	// constrcuter destructer
	DroneS();
	~DroneS();

	// delete Function
	DroneS(const DroneS& _Other) = delete;
	DroneS(DroneS&& _Other) noexcept = delete;
	DroneS& operator=(const DroneS& _Other) = delete;
	DroneS& operator=(DroneS&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);

	void AttEnd(const FrameAnimation_DESC& _Info);
	DroneSUI* MainUI;
	//TerranBaseBullet
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* AuraRenderer;


	SwarmBullet* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;


	int	BulletType;
	bool	BAniChange;
	bool	AttCheck;
	bool	ListLastCheck;
};

