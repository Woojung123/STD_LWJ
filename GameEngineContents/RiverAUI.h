

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class RiverAUI : public GameEngineActor
{
public:
	// constrcuter destructer
	RiverAUI();
	~RiverAUI();

	// delete Function
	RiverAUI(const RiverAUI& _Other) = delete;
	RiverAUI(RiverAUI&& _Other) noexcept = delete;
	RiverAUI& operator=(const RiverAUI& _Other) = delete;
	RiverAUI& operator=(RiverAUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

