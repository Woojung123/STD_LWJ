
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include"StageMain.h"
#include "GlobalContentsValue.h"

// Ό³Έν :
class StageMain;
class UnitBase;
class DragUI;
class Builder;
class GameEngineTextureRenderer;
class GameEngineCollision;
class StageMainCamera;
class UIMouse;
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
	StageMain* m_Stage;
	StageMainCamera* SMainCamera;
	std::vector<UnitBase*> vec_DragUnit;
	bool StartDragCheck;
	bool BuildCheck;
	bool PlusCheck;
	bool SellCheck;
	DragUI* m_DragUI;
	Builder* m_Builder;
	bool BuildColorCheck;


	UIMouse* m_UIMouse;
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
