

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class Plaegue : public UnitBase
{
public:
	// constrcuter destructer
	Plaegue();
	~Plaegue();

	// delete Function
	Plaegue(const Plaegue& _Other) = delete;
	Plaegue(Plaegue&& _Other) noexcept = delete;
	Plaegue& operator=(const Plaegue& _Other) = delete;
	Plaegue& operator=(Plaegue&& _Other) noexcept = delete;


	bool MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other);



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
