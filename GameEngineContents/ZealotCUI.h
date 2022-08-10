

#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class ZealotCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	ZealotCUI();
	~ZealotCUI();

	// delete Function
	ZealotCUI(const ZealotCUI& _Other) = delete;
	ZealotCUI(ZealotCUI&& _Other) noexcept = delete;
	ZealotCUI& operator=(const ZealotCUI& _Other) = delete;
	ZealotCUI& operator=(ZealotCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

