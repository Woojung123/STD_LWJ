
#include "PreCompile.h"
#include "UnitBase.h"

UnitBase::UnitBase() 
		: m_Info({ 0 })
	, m_bClickCheck(false)
	, ClickRenderer(nullptr)
	, AttRenderer(nullptr)
	, ShadowRenderer(nullptr)
	, m_Type(UNITTYPE::NULLTYPE)
{
}

UnitBase::~UnitBase() 
{
}

