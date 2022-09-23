
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"

// Ό³Έν :
class GameEngineTextureRenderer;
class Recall : public UnitBase
{
public:
	// constrcuter destructer
	Recall();
	~Recall();

	// delete Function
	Recall(const Recall& _Other) = delete;
	Recall(Recall&& _Other) noexcept = delete;
	Recall& operator=(const Recall& _Other) = delete;
	Recall& operator=(Recall&& _Other) noexcept = delete;
	bool MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;
	void AttEnd(const FrameAnimation_DESC& _Info);
	bool	BAniChange;
	float4 Color;

private:
	float Speed;
	float4 m_Dir;

	float m_dotDam;

public:
	GameEngineActor* TarGet;
	void SetTarGet(GameEngineActor* _TarGet)
	{
		TarGet = _TarGet;
	}
};

