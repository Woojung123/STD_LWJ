
#pragma once
#include <GameEngineCore/CoreMinimal.h>

// Ό³Έν :
class GameEngineTextureRenderer;
class Builder;
class StageMain;
class DarkMap : public GameEngineActor
{
public:
	// constrcuter destructer
	DarkMap();
	~DarkMap();

	// delete Function
	DarkMap(const DarkMap& _Other) = delete;
	DarkMap(DarkMap&& _Other) noexcept = delete;
	DarkMap& operator=(const DarkMap& _Other) = delete;
	DarkMap& operator=(DarkMap&& _Other) noexcept = delete;
	Builder* m_Bulder;
	GameEngineTextureRenderer* Renderer;

	StageMain* MainStage;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	
	

private:

};
