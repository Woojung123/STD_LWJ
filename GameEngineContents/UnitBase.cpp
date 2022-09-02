
#include "PreCompile.h"
#include "UnitBase.h"
#include "MiniMapUnit.h"

UnitBase::UnitBase() 
		: m_Info({ 0 })
	, m_bClickCheck(false)
	, ClickRenderer(nullptr)
	, AttRenderer(nullptr)
	, ShadowRenderer(nullptr)
	, m_Type(UNITTYPE::NULLTYPE)
	, MiniUnit(nullptr)
	, MiniPlayUnit(nullptr)
{
}

UnitBase::~UnitBase() 
{
}

