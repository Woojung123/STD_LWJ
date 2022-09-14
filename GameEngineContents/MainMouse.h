
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"

// Ό³Έν :
class UnitBase;
class DragUI;
class Builder;
class GameEngineTextureRenderer;
class GameEngineCollision;
class MainMouse : public GameEngineActor
{
public:
	// constrcuter destructer
	MainMouse();
	~MainMouse();

	// delete Function
	MainMouse(const MainMouse& _Other) = delete;
	MainMouse(MainMouse&& _Other) noexcept = delete;
	MainMouse& operator=(const MainMouse& _Other) = delete;
	MainMouse& operator=(MainMouse&& _Other) noexcept = delete;


	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	bool MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool PlayerCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool UICollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool AllCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool MDragCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
public:
	std::vector<UnitBase*> vec_DragUnit;
	bool StartDragCheck;
	bool BuildCheck;
	bool PlusCheck;
	DragUI* m_DragUI;
	Builder* m_Builder;
	bool BuildColorCheck;

	float4 m_DragStartPos;
	float4 m_DragEndPos;

	void DragReset();
	void ClickReset();
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* BuildRenderer;
	GameEngineTextureRenderer* DragRenderer;

	GameEngineCollision* Collision;
	GameEngineCollision* DragCollision;


};
