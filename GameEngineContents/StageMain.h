
#pragma once
#include <GameEngineCore/GameEngineLevel.h>


struct MapPoint
{
	float4 TurnPoint;
	bool	TurnCheck = true;

};

enum  class HellperUnitTYPE
{
	NONE,
	GhostC,
	DragoonC,
	MarineC,
	ZealotC,
	HydraC,
	CorsairC,
	ZeaglingC,
	HighTB,
	PhotoB,
	UltraB,
	ArbitorB,
	DarkTB,
	SunkenB,
	MutalA,
	GardianA,
	CarrierA,
	RiverA,
	ArconA,
	GhostS,
	DroneS,
	ProbeS,
	HydraS,

};

// Ό³Έν :
class PlayNormal;
class DarkTile;
class HPUnit;
class HPUnit;
class HellperWindow;
class StageMain : public GameEngineLevel
{
public:


	// constrcuter destructer
	StageMain();
	~StageMain();

	// delete Function
	StageMain(const StageMain& _Other) = delete;
	StageMain(StageMain&& _Other) noexcept = delete;
	StageMain& operator=(const StageMain& _Other) = delete;
	StageMain& operator=(StageMain&& _Other) noexcept = delete;

	GameEngineSoundPlayer BgmPlayer;
	HPUnit* HPRender[40] = {0};
	std::vector<MapPoint> CheckPoint;
protected:
	void Start() override;
	void Update(float _DeltaTime) override;
	void End() override;
	

public:
	HellperWindow* HellperWindowGUI;
	HellperUnitTYPE Hellpertype = HellperUnitTYPE::NONE;


	PlayNormal* Bicon1;
	PlayNormal* Bicon2;
	PlayNormal* Bicon3;
	bool GameStartB = false;
	float MonHpLevel = 1.f;
	bool GameFinishBool = false;

public:
	int Player_HP = 39;
	int Player_HPRen = 39;

	DarkTile* DTilemap[10][10];

	int Player_Gold = 250;
	int Player_Gas = 0;

	bool MissionC = false;
	bool MissionB = false;
	bool MissionA = false;
	bool MissionZerg = false;
	bool MissionPro = false;
	bool MissionTer = false;
	bool MissionAir = false;


private:
	bool StartCheck;
	float StartTime;
	float GamePlayTime;


	int MonCount;
	int MonMax;

	float MonTimeMax;
	float MonTime;


	int StageCount;



private:
	void Stage1(float _DeltaTime) ;
	void Stage2(float _DeltaTime) ;
	void Stage3(float _DeltaTime) ;
	void Stage4(float _DeltaTime) ;
	void Stage5(float _DeltaTime) ;
	void Stage6(float _DeltaTime) ;
	void Stage7(float _DeltaTime) ;
	void Stage8(float _DeltaTime) ;
	void Stage9(float _DeltaTime) ;
	void Stage10(float _DeltaTime);
	void Stage11(float _DeltaTime);
	void Stage12(float _DeltaTime);
	void Stage13(float _DeltaTime);
	void Stage14(float _DeltaTime);
	void Stage15(float _DeltaTime);
	void Stage16(float _DeltaTime);
	void Stage17(float _DeltaTime);
	void Stage18(float _DeltaTime);
	void Stage19(float _DeltaTime);
	void Stage20(float _DeltaTime);
	void Stage21(float _DeltaTime);
	void Stage22(float _DeltaTime);
	void Stage23(float _DeltaTime);
	void Stage24(float _DeltaTime);
	void Stage25(float _DeltaTime);


};

