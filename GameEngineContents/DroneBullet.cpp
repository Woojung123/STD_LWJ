
#include "PreCompile.h"
#include "DroneBullet.h"
#include "DroneEffect.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>
#include "UnitBase.h"
DroneBullet::DroneBullet()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
{
}

DroneBullet::~DroneBullet()
{
	Death();
}



void DroneBullet::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 60.f,60.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Spore", FrameAnimation_DESC("Spore", 0.1f));
		Renderer->ChangeFrameAnimation("Spore");

	}
	m_Info.Dammage = 20;
}

void DroneBullet::Update(float _DeltaTime)
{


	if (TarGet)
	{

		float4 TargetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();

		if (TargetPos.x <= -1400.f)
		{
			Death();
		}


		m_Dir = (TargetPos - MyPos);
		m_Dir.Normalize();
		GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);

		if ((int)(MyPos.x + 3) > (int)(TargetPos.x) &&
			(int)(MyPos.x - 3) < (int)(TargetPos.x)
			&& (int)(MyPos.y - 3) < (int)(TargetPos.y)
			&& (int)(MyPos.y + 3) > (int)(TargetPos.y))
		{

			////DraBallEff
			DroneEffect* TestUni = GetLevel()->CreateActor<DroneEffect>(OBJECTORDER::Effect);
			TestUni->GetTransform().SetWorldPosition(MyPos);
			((UnitBase*)TarGet)->m_Info.m_Hp -= m_Info.Dammage + UnitBase::SZergUpgrade;
			Death();
		}

	}
	else
	{
		Death();
		return;
	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


}