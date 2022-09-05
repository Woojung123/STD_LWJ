
#include "PreCompile.h"
#include "UnitBase.h"
#include "MiniMapUnit.h"

int UnitBase::CZergUpgrade = 0;
int UnitBase::CProUpgrade = 0;
int UnitBase::CTerUpgrade = 0;

int UnitBase::BZergUpgrade = 0;
int UnitBase::BProUpgrade = 0;
int UnitBase::BTerUpgrade = 0;
					      		      
int UnitBase::AZergUpgrade = 0;
int UnitBase::AProUpgrade = 0;
int UnitBase::ATerUpgrade = 0;
					      					      
int UnitBase::SZergUpgrade = 0;
int UnitBase::SProUpgrade = 0;
int UnitBase::STerUpgrade = 0;


UnitBase::UnitBase() 
		: m_Info({ 0 })
	, m_bClickCheck(false)
	, ClickRenderer(nullptr)
	, AttRenderer(nullptr)
	, ShadowRenderer(nullptr)
	, m_Type(UNITTYPE::NULLTYPE)
	, MiniUnit(nullptr)
	, MiniPlayUnit(nullptr)
	,Collision(nullptr)
	, m_bDragCheck(false)
{
}

UnitBase::~UnitBase() 
{
}

