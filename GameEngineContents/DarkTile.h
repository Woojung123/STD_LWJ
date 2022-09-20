
#pragma once
#include <GameEngineCore/CoreMinimal.h>



// Ό³Έν :
class GameEngineTextureRenderer;
class Builder;
class StageMainCamera;
class DarkTile : public GameEngineActor
{
public:
	// constrcuter destructer
	DarkTile();
	~DarkTile();

	// delete Function
	DarkTile(const DarkTile& _Other) = delete;
	DarkTile(DarkTile&& _Other) noexcept = delete;
	DarkTile& operator=(const DarkTile& _Other) = delete;
	DarkTile& operator=(DarkTile&& _Other) noexcept = delete;
	
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	
public:
	int Tilestate = 0;
	float Tilealpha = 1.f;
	float4 ScreenPos = {};

	StageMainCamera* M_Camera;
private:

};
