

#pragma once
#include <GameEngineCore/CoreMinimal.h>

// ???? :
class GameEngineTextureRenderer;
class SingleButton : public GameEngineActor
{
public:
	// constrcuter destructer
	SingleButton();
	~SingleButton();

	// delete Function
	SingleButton(const SingleButton& _Other) = delete;
	SingleButton(SingleButton&& _Other) noexcept = delete;
	SingleButton& operator=(const SingleButton& _Other) = delete;
	SingleButton& operator=(SingleButton&& _Other) noexcept = delete;

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
