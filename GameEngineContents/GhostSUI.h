

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GhostSUI : public GameEngineActor
{
public:
	// constrcuter destructer
	GhostSUI();
	~GhostSUI();

	// delete Function
	GhostSUI(const GhostSUI& _Other) = delete;
	GhostSUI(GhostSUI&& _Other) noexcept = delete;
	GhostSUI& operator=(const GhostSUI& _Other) = delete;
	GhostSUI& operator=(GhostSUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

