#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"

// Ό³Έν :
class MiniMapUnit;
class MiniMapPlayer;
class GameEngineCollision;
class UnitBase : public GameEngineActor
{
public:
	// constrcuter destructer
	UnitBase();
	~UnitBase();

	// delete Function
	UnitBase(const UnitBase& _Other) = delete;
	UnitBase(UnitBase&& _Other) noexcept = delete;
	UnitBase& operator=(const UnitBase& _Other) = delete;
	UnitBase& operator=(UnitBase&& _Other) noexcept = delete;

public:
	UINFO	m_Info;
	UNITTYPE m_Type;
	MiniMapUnit* MiniUnit;
	MiniMapPlayer* MiniPlayUnit;
	bool	m_bClickCheck;
	GameEngineCollision* Collision;

	GameEngineTextureRenderer* ShadowRenderer;
	GameEngineTextureRenderer* AttRenderer;
	GameEngineTextureRenderer* ClickRenderer;
};
