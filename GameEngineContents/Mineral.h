

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :


class GameEngineTextureRenderer;
class Mineral : public UnitBase
{
public:
	// constrcuter destructer
	Mineral();
	~Mineral();

	// delete Function
	Mineral(const Mineral& _Other) = delete;
	Mineral(Mineral&& _Other) noexcept = delete;
	Mineral& operator=(const Mineral& _Other) = delete;
	Mineral& operator=(Mineral&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void AttEnd(const FrameAnimation_DESC& _Info);
	GameEngineTextureRenderer* Renderer;



	float Reach;
public:
	float	Speed;

	bool	AttCheck;
	bool	ListLastCheck;
};

