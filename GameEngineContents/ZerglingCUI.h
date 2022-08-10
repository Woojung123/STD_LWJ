
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class ZerglingCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	ZerglingCUI();
	~ZerglingCUI();

	// delete Function
	ZerglingCUI(const ZerglingCUI& _Other) = delete;
	ZerglingCUI(ZerglingCUI&& _Other) noexcept = delete;
	ZerglingCUI& operator=(const ZerglingCUI& _Other) = delete;
	ZerglingCUI& operator=(ZerglingCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

