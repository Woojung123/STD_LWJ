
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class NexusUI;
class GameEngineTextureRenderer;
class Nexus : public UnitBase
{
public:
	// constrcuter destructer
	Nexus();
	~Nexus();

	// delete Function
	Nexus(const Nexus& _Other) = delete;
	Nexus(Nexus&& _Other) noexcept = delete;
	Nexus& operator=(const Nexus& _Other) = delete;
	Nexus& operator=(Nexus&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	NexusUI* MainUI;
	void AttEnd(const FrameAnimation_DESC& _Info);
	GameEngineTextureRenderer* Renderer;



	float Reach;
public:
	float	Speed;

	bool	AttCheck;
	bool	ListLastCheck;
};

