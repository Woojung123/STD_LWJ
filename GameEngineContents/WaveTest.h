

#pragma once
#include <GameEngineCore/CoreMinimal.h>




struct PixelWData
{
	float4 MulColor;
	float4 PlusColor;
	float4 Slice;


	PixelWData()
		: MulColor(float4::WHITE)
		, PlusColor(float4::ZERO)
		, Slice(float4::ZERO)

	{

	}


};




struct WaveAtlasData
{
	public:
		float4 FrameData;
		float4 PivotPos;
};








// Ό³Έν :
class WaveTest : public GameEngineActor
{
public:
	// constrcuter destructer
	WaveTest();
	~WaveTest();

	// delete Function
	WaveTest(const WaveTest& _Other) = delete;
	WaveTest(WaveTest&& _Other) noexcept = delete;
	WaveTest& operator=(const WaveTest& _Other) = delete;
	WaveTest& operator=(WaveTest&& _Other) noexcept = delete;

protected:
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	GameEngineTextureRenderer* Renderer;


	PixelWData PixelDataInst;
	WaveAtlasData AtlasDataInst;


private:

};
