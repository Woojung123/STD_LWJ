
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class DroneSUI : public GameEngineActor
{
public:
	// constrcuter destructer
	DroneSUI();
	~DroneSUI();

	// delete Function
	DroneSUI(const DroneSUI& _Other) = delete;
	DroneSUI(DroneSUI&& _Other) noexcept = delete;
	DroneSUI& operator=(const DroneSUI& _Other) = delete;
	DroneSUI& operator=(DroneSUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

