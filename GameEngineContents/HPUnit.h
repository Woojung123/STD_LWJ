
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :


class GameEngineTextureRenderer;
class HPUnit : public UnitBase
{
public:
	// constrcuter destructer
	HPUnit();
	~HPUnit();

	// delete Function
	HPUnit(const HPUnit& _Other) = delete;
	HPUnit(HPUnit&& _Other) noexcept = delete;
	HPUnit& operator=(const HPUnit& _Other) = delete;
	HPUnit& operator=(HPUnit&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;

};

