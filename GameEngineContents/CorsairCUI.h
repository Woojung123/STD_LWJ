
#pragma once
#include <GameEngineCore/GameEngineActor.h>

// Ό³Έν :
class CorsairCUI : public GameEngineActor
{
public:
	// constrcuter destructer
	CorsairCUI();
	~CorsairCUI();

	// delete Function
	CorsairCUI(const CorsairCUI& _Other) = delete;
	CorsairCUI(CorsairCUI&& _Other) noexcept = delete;
	CorsairCUI& operator=(const CorsairCUI& _Other) = delete;
	CorsairCUI& operator=(CorsairCUI&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime) {}
	void End() {}

private:

};

