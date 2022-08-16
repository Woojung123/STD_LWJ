
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class UpgradeAUI;
class DraBall;
class GameEngineTextureRenderer;
class UpgradeA : public UnitBase
{
public:
	// constrcuter destructer
	UpgradeA();
	~UpgradeA();

	// delete Function
	UpgradeA(const UpgradeA& _Other) = delete;
	UpgradeA(UpgradeA&& _Other) noexcept = delete;
	UpgradeA& operator=(const UpgradeA& _Other) = delete;
	UpgradeA& operator=(UpgradeA&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	UpgradeAUI* MainUI;
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

