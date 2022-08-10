

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// ���� :
class MarinCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	MarinCUI();
	~MarinCUI();

	// delete Function
	MarinCUI(const MarinCUI& _Other) = delete;
	MarinCUI(MarinCUI&& _Other) noexcept = delete;
	MarinCUI& operator=(const MarinCUI& _Other) = delete;
	MarinCUI& operator=(MarinCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

