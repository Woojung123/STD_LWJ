
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"

// Ό³Έν :
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
public:


	bool BuildCheck;
	bool PlusCheck;

	Builder* m_Builder;
	bool BuildColorCheck;

	void ClickReset();
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* BuildRenderer;
	GameEngineCollision* Collision;

};
