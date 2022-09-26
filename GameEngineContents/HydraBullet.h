
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class HydraBullet : public UnitBase
{
public:
	// constrcuter destructer
	HydraBullet();
	~HydraBullet();

	// delete Function
	HydraBullet(const HydraBullet& _Other) = delete;
	HydraBullet(HydraBullet&& _Other) noexcept = delete;
	HydraBullet& operator=(const HydraBullet& _Other) = delete;
	HydraBullet& operator=(HydraBullet&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	GameEngineTextureRenderer* Renderer;
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange = false;

public:
	void ChangeAni(float4 _Gopoint, float4 _WorldPos, float4 m_Dir);
};

