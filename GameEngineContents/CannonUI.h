
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CannonUI : public GameEngineActor
{
public:
	// constrcuter destructer
	CannonUI();
	~CannonUI();

	// delete Function
	CannonUI(const CannonUI& _Other) = delete;
	CannonUI(CannonUI&& _Other) noexcept = delete;
	CannonUI& operator=(const CannonUI& _Other) = delete;
	CannonUI& operator=(CannonUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

