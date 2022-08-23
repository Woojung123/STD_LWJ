

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class Builder;
class GameEngineTextureRenderer;
class BuildImage : public UnitBase
{
public:
	// constrcuter destructer
	BuildImage();
	~BuildImage();

	// delete Function
	BuildImage(const BuildImage& _Other) = delete;
	BuildImage(BuildImage&& _Other) noexcept = delete;
	BuildImage& operator=(const BuildImage& _Other) = delete;
	BuildImage& operator=(BuildImage&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;

	GameEngineTextureRenderer* Renderer;

	float4 Color;

public:

	int Buildingtype;
	float Speed;
	float4 m_Dir;

public:
	Builder* m_Bulder;

};
