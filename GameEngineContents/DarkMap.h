
#pragma once
#include <GameEngineCore/CoreMinimal.h>



struct DarkPixelData
{
	float4 MulColor;
	float4 PlusColor;
	float4 Slice;

	DarkPixelData()
		: MulColor(float4::WHITE)
		, PlusColor(float4::ZERO)
		, Slice(float4::ZERO)
		
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

	DarkPixelData PixelDataInst;
	DarkAtlasData AtlasDataInst;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	
	
	float sumDelta = 0.f;
private:

};
