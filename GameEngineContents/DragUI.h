

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MainMouse;
class DragUI : public GameEngineActor
{
public:
	// constrcuter destructer
	DragUI();
	~DragUI();

	// delete Function
	DragUI(const DragUI& _Other) = delete;
	DragUI(DragUI&& _Other) noexcept = delete;
	DragUI& operator=(const DragUI& _Other) = delete;
	DragUI& operator=(DragUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

public:
	MainMouse* m_Mouse;
	GameEngineUIRenderer* Renderer1;
	GameEngineUIRenderer* Renderer2;
	GameEngineUIRenderer* Renderer3;
	GameEngineUIRenderer* Renderer4;
	GameEngineUIRenderer* Renderer5;
	GameEngineUIRenderer* Renderer6;
	GameEngineUIRenderer* Renderer7;
	GameEngineUIRenderer* Renderer8;
	GameEngineUIRenderer* Renderer9;
	GameEngineUIRenderer* Renderer10;
	GameEngineUIRenderer* Renderer11;
	GameEngineUIRenderer* Renderer12;
	void DragOnOff();

public:
	int DragSize;


	bool BuildCollision(GameEngineCollision* _This, GameEngineCollision* _Other);
	bool MakeCollision(GameEngineCollision* _This, GameEngineCollision* _Other);

};

