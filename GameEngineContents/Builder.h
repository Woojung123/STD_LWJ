
#pragma once
#include <GameEngineCore/CoreMinimal.h>
#include "UnitBase.h"
// Ό³Έν :
class StageMain;
class MainMouse;
class BuilderUI;

class MiniMapPlayer;
class SwarmBullet;
class GameEngineTextureRenderer;
class Builder : public UnitBase
{
public:
	// constrcuter destructer
	Builder();
	~Builder();

	// delete Function
	Builder(const Builder& _Other) = delete;
	Builder(Builder&& _Other) noexcept = delete;
	Builder& operator=(const Builder& _Other) = delete;
	Builder& operator=(Builder&& _Other) noexcept = delete;

	StageMain* m_Stage;
protected:
	//void AttEnd(const FrameAnimation_DESC& _Info);
	void Start() override;
	void Update(float _DeltaTime);
	void End() {}

	void ChangeAni(float4 _Gopoint, float4 _WorldPos);
	float4 WorldPos = {};
	float4 MyPos = {};
	void AttEnd(const FrameAnimation_DESC& _Info);
	BuilderUI* MainUI;
	//TerranBaseBullet


	void MoveCheck(float _DeltaTime);


	
	GameEngineTextureRenderer* Renderer;
	SwarmBullet* TestUni;
	float4 Color;
	float Reach;
public:
	bool Movecheck;
	MiniMapPlayer* MiniPlayUnit;

	MainMouse* m_MainMouse;

	bool BuildCheck;
	float4 BuildPos;

	bool SpeedReset;

	float	Speed;
	float	AttTime;
	float	AttTimeMax;
	float4	m_Dir;

	bool	BAniChange;
	bool	AttCheck;
	bool	ListLastCheck;

	int GradeType;
	bool BuildMake;

	int m_DraC;
	int m_GhostC;
	int m_MarinC;
	int m_ZealotC;
	int m_HydraC;
	int m_CorsairC;
	int m_ZerglingC;
	int m_HighTB;
	int m_PhotoB;
	int m_UltraB;
	int m_ArbitorB;
	int m_DarkTB;
	int m_SunkenB;
	int m_MutalA;
	int m_GardianA;
	int m_CarrierA;
	int m_RiverA;
	int m_ArconA;
	int m_GhostS;
	int m_DroneS;
	int m_ProbeS;
	int m_HydraS;


};

