
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class HydraSUI : public GameEngineActor
{
public:
	// constrcuter destructer
	HydraSUI();
	~HydraSUI();

	// delete Function
	HydraSUI(const HydraSUI& _Other) = delete;
	HydraSUI(HydraSUI&& _Other) noexcept = delete;
	HydraSUI& operator=(const HydraSUI& _Other) = delete;
	HydraSUI& operator=(HydraSUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

