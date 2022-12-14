
#pragma once
#include <GameEngineCore/CoreMinimal.h>

// ???? :
class MiniCamera;
class GameEngineTextureRenderer;
class StageMainCamera : public GameEngineActor
{
public:
	// constrcuter destructer
	StageMainCamera();
	~StageMainCamera();

	// delete Function
	StageMainCamera(const StageMainCamera& _Other) = delete;
	StageMainCamera(StageMainCamera&& _Other) noexcept = delete;
	StageMainCamera& operator=(const StageMainCamera& _Other) = delete;
	StageMainCamera& operator=(StageMainCamera&& _Other) noexcept = delete;


	MiniCamera* MiniCameraUI;
	bool MiniOnOff = false;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

private:
	float Speed;
};

