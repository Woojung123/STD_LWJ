

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class GhostCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	GhostCUI();
	~GhostCUI();

	// delete Function
	GhostCUI(const GhostCUI& _Other) = delete;
	GhostCUI(GhostCUI&& _Other) noexcept = delete;
	GhostCUI& operator=(const GhostCUI& _Other) = delete;
	GhostCUI& operator=(GhostCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

