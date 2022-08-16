
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class UpgradeCUI;
class DraBall;
class GameEngineTextureRenderer;
class UpgradeC : public UnitBase
{
public:
	// constrcuter destructer
	UpgradeC();
	~UpgradeC();

	// delete Function
	UpgradeC(const UpgradeC& _Other) = delete;
	UpgradeC(UpgradeC&& _Other) noexcept = delete;
	UpgradeC& operator=(const UpgradeC& _Other) = delete;
	UpgradeC& operator=(UpgradeC&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	UpgradeCUI* MainUI;
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

