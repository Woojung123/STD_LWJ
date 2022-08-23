
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class GameEngineTextureRenderer;
class Tileobject : public UnitBase
{
public:
	// constrcuter destructer
	Tileobject();
	~Tileobject();

	// delete Function
	Tileobject(const Tileobject& _Other) = delete;
	Tileobject(Tileobject&& _Other) noexcept = delete;
	Tileobject& operator=(const Tileobject& _Other) = delete;
	Tileobject& operator=(Tileobject&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;
	

};


