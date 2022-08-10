
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class HydraSUI;
class Plaegue;
class GameEngineTextureRenderer;
class HydraS : public UnitBase
{
public:
	// constrcuter destructer
	HydraS();
	~HydraS();

	// delete Function
	HydraS(const HydraS& _Other) = delete;
	HydraS(HydraS&& _Other) noexcept = delete;
	HydraS& operator=(const HydraS& _Other) = delete;
	HydraS& operator=(HydraS&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	GameEngineTextureRenderer* AuraRenderer;

	HydraSUI* MainUI;
	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;
	Plaegue* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;

	bool	AttCheck;
	bool	ListLastCheck;
};

