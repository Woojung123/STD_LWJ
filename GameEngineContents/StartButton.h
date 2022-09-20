
#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
class GameEngineTextureRenderer;
class StartButton : public GameEngineActor
{
public:
	// constrcuter destructer
	StartButton();
	~StartButton();

	// delete Function
	StartButton(const StartButton& _Other) = delete;
	StartButton(StartButton&& _Other) noexcept = delete;
	StartButton& operator=(const StartButton& _Other) = delete;
	StartButton& operator=(StartButton&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	GameEngineCollision* Collision;
	GameEngineTextureRenderer* Renderer[2];

	bool Collcheck(GameEngineCollision* _This, GameEngineCollision* _Other);

private:
	GameEngineFontRenderer* Font;


	float timecheck = 0.f;
};
