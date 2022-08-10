
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DragoonCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	DragoonCUI();
	~DragoonCUI();

	// delete Function
	DragoonCUI(const DragoonCUI& _Other) = delete;
	DragoonCUI(DragoonCUI&& _Other) noexcept = delete;
	DragoonCUI& operator=(const DragoonCUI& _Other) = delete;
	DragoonCUI& operator=(DragoonCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

