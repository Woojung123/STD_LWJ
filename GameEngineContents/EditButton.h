

#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
class GameEngineTextureRenderer;
class EditButton : public GameEngineActor
{
public:
	// constrcuter destructer
	EditButton();
	~EditButton();

	// delete Function
	EditButton(const EditButton& _Other) = delete;
	EditButton(EditButton&& _Other) noexcept = delete;
	EditButton& operator=(const EditButton& _Other) = delete;
	EditButton& operator=(EditButton&& _Other) noexcept = delete;

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
