
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class StageMain;
class Builder;
class GameEngineFontRenderer;
class StageMainCamera;
class GameEngineTextureRenderer;
class PlayNormal : public UnitBase
{
public:
	// constrcuter destructer
	PlayNormal();
	~PlayNormal();

	// delete Function
	PlayNormal(const PlayNormal& _Other) = delete;
	PlayNormal(PlayNormal&& _Other) noexcept = delete;
	PlayNormal& operator=(const PlayNormal _Other) = delete;
	PlayNormal& operator=(PlayNormal&& _Other) noexcept = delete;


	int BiconType = 0;
	float Sumdeta;
	bool Deltacheck = false;

	StageMain* m_STMain;
	Builder* m_Builder;
	StageMainCamera* m_MainCamera;
	GameEngineFontRenderer* Font;


	bool coll(GameEngineCollision* _This, GameEngineCollision* _Other);
protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* fRenderer;
	GameEngineTextureRenderer* Renderer;




};

