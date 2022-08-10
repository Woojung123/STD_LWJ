
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class HydraCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	HydraCUI();
	~HydraCUI();

	// delete Function
	HydraCUI(const HydraCUI& _Other) = delete;
	HydraCUI(HydraCUI&& _Other) noexcept = delete;
	HydraCUI& operator=(const HydraCUI& _Other) = delete;
	HydraCUI& operator=(HydraCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

