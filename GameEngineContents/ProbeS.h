

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class ProbeSUI;
class SwarmBullet;
class GameEngineTextureRenderer;
class ProbeS : public UnitBase
{
public:
	// constrcuter destructer
	ProbeS();
	~ProbeS();

	// delete Function
	ProbeS(const ProbeS& _Other) = delete;
	ProbeS(ProbeS&& _Other) noexcept = delete;
	ProbeS& operator=(const ProbeS& _Other) = delete;
	ProbeS& operator=(ProbeS&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);

	void AttEnd(const FrameAnimation_DESC& _Info);
	ProbeSUI* MainUI;
	//TerranBaseBullet

	GameEngineTextureRenderer* AuraRenderer;

	GameEngineTextureRenderer* Renderer;
	SwarmBullet* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;

	bool	BAniChange;
	bool	AttCheck;
	bool	ListLastCheck;
};

