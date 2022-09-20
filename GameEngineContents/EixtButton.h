

#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
class GameEngineTextureRenderer;
class EixtButton : public GameEngineActor
{
public:
	// constrcuter destructer
	EixtButton();
	~EixtButton();

	// delete Function
	EixtButton(const EixtButton& _Other) = delete;
	EixtButton(EixtButton&& _Other) noexcept = delete;
	EixtButton& operator=(const EixtButton& _Other) = delete;
	EixtButton& operator=(EixtButton&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	GameEngineCollision* Collision;
	GameEngineTextureRenderer* Renderer[2];

	bool Collcheck(GameEngineCollision* _This, GameEngineCollision* _Other);

	GameEngineFontRenderer* Font;
	float timecheck = 0.f;
private:

};
