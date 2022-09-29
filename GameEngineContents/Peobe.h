

#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :

class ProbeSUI;
class GameEngineTextureRenderer;
class Peobe : public UnitBase
{
public:
	// constrcuter destructer
	Peobe();
	~Peobe();

	// delete Function
	Peobe(const Peobe& _Other) = delete;
	Peobe(Peobe&& _Other) noexcept = delete;
	Peobe& operator=(const Peobe& _Other) = delete;
	Peobe& operator=(Peobe&& _Other) noexcept = delete;

protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}
	ProbeSUI* MainUI;
	void AttEnd(const FrameAnimation_DESC& _Info);
	GameEngineTextureRenderer* Renderer;
	GameEngineTextureRenderer* Renderermineral;
	void ChangeAni(float4 _Gopoint, float4 _WorldPos);

	float4	m_Dir;

	float Reach;
public:
	bool MineralCheck = false;
	bool MineralOn = false;


	bool DirCheck = true;


	bool SleepTimecheck = false;
	float Sleeptime = 0.f;

	float4 MineralPos = {-1345.f, -240.f, 0.f};
	float4 nexusPos = { -512.f,-240.f,0.f };


	float	Speed;

	bool	AttCheck;
	bool	ListLastCheck;
};

