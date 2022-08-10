
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class UltraCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	UltraCUI();
	~UltraCUI();

	// delete Function
	UltraCUI(const UltraCUI& _Other) = delete;
	UltraCUI(UltraCUI&& _Other) noexcept = delete;
	UltraCUI& operator=(const UltraCUI& _Other) = delete;
	UltraCUI& operator=(UltraCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

