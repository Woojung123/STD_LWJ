
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GardianAUI : public GameEngineActor
{
public:
	// constrcuter destructer
	GardianAUI();
	~GardianAUI();

	// delete Function
	GardianAUI(const GardianAUI& _Other) = delete;
	GardianAUI(GardianAUI&& _Other) noexcept = delete;
	GardianAUI& operator=(const GardianAUI& _Other) = delete;
	GardianAUI& operator=(GardianAUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

