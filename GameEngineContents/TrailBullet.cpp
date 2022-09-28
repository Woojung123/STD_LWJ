


#include "PreCompile.h"
#include "TrailBullet.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineBase\GameEngineRandom.h>
#include "ProbeS.h"
#include "UnitBase.h"
#include "ProbeTrail.h"


TrailBullet::TrailBullet()
	: Speed(0.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, DamCheck(false)
{
}

TrailBullet::~TrailBullet()
{

}




void TrailBullet::Start()
{


	


	Pos.x = GameEngineRandom::MainRandom.RandomFloat(-50, 50);
	Pos.y = GameEngineRandom::MainRandom.RandomFloat(-50, 50);
	Pos.z = -45.f;
	Pos.w = 1.0f;

	DirPower = float4::ZERO;


	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 20.f,20.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Draball", FrameAnimation_DESC("Draball", 0.1f));
		Renderer->ChangeFrameAnimation("Draball");

	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 20.0f, 20.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}


	Death(5.f);

	m_Info.Dammage = 0.001;
}


bool TrailBullet::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	m_Info.Dammage = 10.f;
	GameEngineActor* Dest = _Other->GetActor();

	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage + (UnitBase::SProUpgrade * 3);

	return false;
}



void TrailBullet::Update(float _DeltaTime)
{

	TarGet = m_Probe->TarGet;


	if (m_Probe->GetTransform().GetWorldPosition().x <= -1400.f)
	{
		Death();
		return;


	}


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&TrailBullet::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);


	if (TarGet)
	{


	


	

		float4 TargetPos2 = TarGet->GetTransform().GetWorldPosition();

		float4 TargetPos = TargetPos2 - Pos;





		if (TargetPos.x <= -1400.f)
		{
			Death();
		}



		float4 MyPos = GetTransform().GetWorldPosition();

		Speed += _DeltaTime;

		if (Speed >= 0.0125f)
		{
			Speed -= 0.0125f;

			ProbeTrail* TestUni = GetLevel()->CreateActor<ProbeTrail>(OBJECTORDER::Effect);
			TestUni->GetTransform().SetWorldPosition(MyPos);

		}




		float4 MoveDir = GetTransform().GetRightVector();

		float4 TargetDir = (TargetPos - MyPos).NormalizeReturn();


		float4 Cross = float4::Cross(MoveDir, TargetDir);

		// ¿ÞÂÊ 
		if (Cross.z > 0)
		{
			GetTransform().SetAddWorldRotation(float4(0.0f, 0.0f, 720.f * _DeltaTime));
		}
		// ¿À¸¥ÂÊ
		else
		{
			GetTransform().SetAddWorldRotation(float4(0.0f, 0.0f, -720.f * _DeltaTime));
		}



		DirPower += GetTransform().GetRightVector()  * 1000.f* _DeltaTime;

		if (DirPower.x >= 300.f)
		{
			DirPower.x = 300.f;
		}
		if (DirPower.x <= -300.f)
		{
			DirPower.x = -300.f;
		}


		if (DirPower.y >= 200.f)
		{
			DirPower.y = 200.f;
		}
		if (DirPower.y <= -200.f)
		{
			DirPower.y = -200.f;
		}
		
		// DirPower += Normal * 100.0f * _DeltaTime;
		//DirPower.Normalize();

		GetTransform().SetWorldMove(DirPower * 3.f *_DeltaTime);


	}
	else
	{
		Death();
	}




	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


}