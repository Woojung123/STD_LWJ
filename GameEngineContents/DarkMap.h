
#pragma once
#include <GameEngineCore/CoreMinimal.h>



struct PixelTData
{
	float4 MulColor;
	float4 PlusColor;
	float4 Slice;
	float4 Pos[50][50];


	PixelTData()
		: MulColor(float4::WHITE)
		, PlusColor(float4::ZERO)
		, Slice(float4::ZERO)
		, Pos()
		
	{

	}
};

struct DarkAtlasData
{
public:
	float4 FrameData;
	float4 PivotPos;
};






// Ό³Έν :
class GameEngineTextureRenderer;
class Builder;
class StageMainCamera;
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
	StageMainCamera* M_Camera;
	StageMain* MainStage;

	PixelTData PixelDataInst;
	DarkAtlasData AtlasDataInst;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	
	float4 PosTile[50][50];
	float sumDelta = 0.f;
private:

};
