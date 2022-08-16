
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class UpgradeBUI;
class DraBall;
class GameEngineTextureRenderer;
class UpgradeB : public UnitBase
{
public:
	// constrcuter destructer
	UpgradeB();
	~UpgradeB();

	// delete Function
	UpgradeB(const UpgradeB& _Other) = delete;
	UpgradeB(UpgradeB&& _Other) noexcept = delete;
	UpgradeB& operator=(const UpgradeB& _Other) = delete;
	UpgradeB& operator=(UpgradeB&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	UpgradeBUI* MainUI;
	void AttEnd(const FrameAnimation_DESC& _Info);
	GameEngineTextureRenderer* Renderer;
	DraBall* TestUni;


	int	AttCount;
	int	AttCountMax;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;

	bool	AttCheck;
	bool	ListLastCheck;
};

