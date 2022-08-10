

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class ProbeSUI : public GameEngineActor
{
public:
	// constrcuter destructer
	ProbeSUI();
	~ProbeSUI();

	// delete Function
	ProbeSUI(const ProbeSUI& _Other) = delete;
	ProbeSUI(ProbeSUI&& _Other) noexcept = delete;
	ProbeSUI& operator=(const ProbeSUI& _Other) = delete;
	ProbeSUI& operator=(ProbeSUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

