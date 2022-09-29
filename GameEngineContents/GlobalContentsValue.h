#pragma once
//#include "Player.h"
//#include "Monster.h"

enum class OBJECTORDER
{
	TileMap,
	Player,
	Monster,
	BackGround,
	Camera,
	Bullet,
	Effect,
	Mouse,
	MouseUI,
	MouseDrag,
	Mineral,
	Probe,
	Life,
	UI = 1000,
};

enum class UNITTYPE
{
	DraC,
	GhostC,
	MarinC,
	ZealotC,
	HydraC,
	CorsairC,
	ZerglingC,
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
	Builder,
	NULLTYPE


};



typedef struct UnitInfo
{
	float m_Hp;
	float m_MaxHp;
	int Gold;
	float Dammage;


}UINFO;


// Ό³Έν :
class GlobalContentsValue
{
public:
	class Enums 
	{
	};

	class Actors 
	{
	public:
		//static Monster* TestMonster;

	private:
		Actors() {		}
		~Actors() {		}
	};

private:
	GlobalContentsValue()	{	}

	~GlobalContentsValue()	{	}
};

