

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class ArconAUI : public GameEngineActor
{
public:
	// constrcuter destructer
	ArconAUI();
	~ArconAUI();

	// delete Function
	ArconAUI(const ArconAUI& _Other) = delete;
	ArconAUI(ArconAUI&& _Other) noexcept = delete;
	ArconAUI& operator=(const ArconAUI& _Other) = delete;
	ArconAUI& operator=(ArconAUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

