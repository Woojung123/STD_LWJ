
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class MutalAUI : public GameEngineActor
{
public:
	// constrcuter destructer
	MutalAUI();
	~MutalAUI();

	// delete Function
	MutalAUI(const MutalAUI& _Other) = delete;
	MutalAUI(MutalAUI&& _Other) noexcept = delete;
	MutalAUI& operator=(const MutalAUI& _Other) = delete;
	MutalAUI& operator=(MutalAUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};


