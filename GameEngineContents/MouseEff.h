

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class MouseEff : public UnitBase
{
public:
	// constrcuter destructer
	MouseEff();
	~MouseEff();

	// delete Function
	MouseEff(const MouseEff& _Other) = delete;
	MouseEff(MouseEff&& _Other) noexcept = delete;
	MouseEff& operator=(const MouseEff& _Other) = delete;
	MouseEff& operator=(MouseEff&& _Other) noexcept = delete;

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
