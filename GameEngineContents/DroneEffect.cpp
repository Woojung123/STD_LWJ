

#include "PreCompile.h"
#include "DroneEffect.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
DroneEffect::DroneEffect()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

DroneEffect::~DroneEffect()
{
	Death();
}

void DroneEffect::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void DroneEffect::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });
		Renderer->GetPixelData().MulColor.a = 0.5f;
		Renderer->CreateFrameAnimationFolder("Ensare", FrameAnimation_DESC("Ensare", 0.1f));
		Renderer->ChangeFrameAnimation("Ensare");
		Renderer->AnimationBindEnd("Ensare", &DroneEffect::AttEnd, this);
	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 128.0f, 128.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}
	m_Info.Dammage = 1;



}


bool DroneEffect::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{


	GameEngineActor* Dest = _Other->GetActor();

	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage + UnitBase::SZergUpgrade;

	return false;
}



void DroneEffect::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&DroneEffect::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);




}