

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class ProbeTrail : public UnitBase
{
public:
	// constrcuter destructer
	ProbeTrail();
	~ProbeTrail();

	// delete Function
	ProbeTrail(const ProbeTrail& _Other) = delete;
	ProbeTrail(ProbeTrail&& _Other) noexcept = delete;
	ProbeTrail& operator=(const ProbeTrail& _Other) = delete;
	ProbeTrail& operator=(ProbeTrail&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	GameEngineTextureRenderer* Renderer;

	float4 Color;

private:
	float Speed;
	float4 m_Dir;

};
