

#pragma once
#include <GameEngineCore/GameEngineActor.h>


struct DminiPixelData
{
	float4 MulColor;
	float4 PlusColor;
	float4 Slice;

	DminiPixelData()
		: MulColor(float4::WHITE)
		, PlusColor(float4::ZERO)
		, Slice(float4::ZERO)

	{

	}
};

struct DMiniAtlasData
{
public:
	float4 FrameData;
	float4 PivotPos;
};



// Ό³Έν :
class Builder;
class MiniMap : public GameEngineActor
{
public:
	// constrcuter destructer
	MiniMap();
	~MiniMap();

	// delete Function
	MiniMap(const MiniMap& _Other) = delete;
	MiniMap(MiniMap&& _Other) noexcept = delete;
	MiniMap& operator=(const MiniMap& _Other) = delete;
	MiniMap& operator=(MiniMap&& _Other) noexcept = delete;
	Builder* m_Bulder;
protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

private:

	DminiPixelData PixelDataInst;
	DMiniAtlasData AtlasDataInst;
	GameEngineUIRenderer* DMiniRenderer;


};

