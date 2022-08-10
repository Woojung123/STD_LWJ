
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class SunkenCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	SunkenCUI();
	~SunkenCUI();

	// delete Function
	SunkenCUI(const SunkenCUI& _Other) = delete;
	SunkenCUI(SunkenCUI&& _Other) noexcept = delete;
	SunkenCUI& operator=(const SunkenCUI& _Other) = delete;
	SunkenCUI& operator=(SunkenCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

