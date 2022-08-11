
#include "PreCompile.h"
#include "UnitBase.h"

UnitBase::UnitBase() 
		: m_Info({ 0 })
	, m_bClickCheck(false)
	, ClickRenderer(nullptr)
	, AttRenderer(nullptr)
{
}

UnitBase::~UnitBase() 
{
}

