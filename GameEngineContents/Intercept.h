
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class Carrier;
class mutalBullet;
class GameEngineTextureRenderer;
class Intercept : public UnitBase
{
public:
	// constrcuter destructer
	Intercept();
	~Intercept();

	// delete Function
	Intercept(const Intercept& _Other) = delete;
	Intercept(Intercept&& _Other) noexcept = delete;
	Intercept operator=(const Intercept& _Other) = delete;
	Intercept& operator=(Intercept&& _Other) noexcept = delete;

public:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	GameEngineTextureRenderer* Renderer;
	GameEngineActor* TarGet;

	Carrier* Mycarrier;
	mutalBullet* TestUni;
	float4 Color;
	float Reach;
public:
	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4 GoPoint;
	float4	m_Dir;


	bool	soundcheck = false;
	bool	BAniChange;
	bool	AttCheck;
	bool	MVcheck = true;
	bool	ListLastCheck;




	int		AttCount;
	int		AttCountMax;




};

