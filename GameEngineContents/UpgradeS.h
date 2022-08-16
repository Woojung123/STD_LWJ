
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class UpgradeSUI;
class DraBall;
class GameEngineTextureRenderer;
class UpgradeS : public UnitBase
{
public:
	// constrcuter destructer
	UpgradeS();
	~UpgradeS();

	// delete Function
	UpgradeS(const UpgradeS& _Other) = delete;
	UpgradeS(UpgradeS&& _Other) noexcept = delete;
	UpgradeS& operator=(const UpgradeS& _Other) = delete;
	UpgradeS& operator=(UpgradeS&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	UpgradeSUI* MainUI;
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

