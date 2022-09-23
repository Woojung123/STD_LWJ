

#include "PreCompile.h"
#include "SwarmEffect.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
SwarmEffect::SwarmEffect()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
	, collcheck(false)
	, colTime(0)
{
}

SwarmEffect::~SwarmEffect()
{
	Death();
}

void SwarmEffect::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void SwarmEffect::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 250.f,200.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("dswarm", FrameAnimation_DESC("dswarm", 0.05f));
		Renderer->ChangeFrameAnimation("dswarm");
		Renderer->AnimationBindEnd("dswarm", &SwarmEffect::AttEnd, this);
		Renderer->GetPixelData().MulColor.a = 0.5f;
	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 250.0f, 200.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}
	m_Info.Dammage = 4;

}


bool SwarmEffect::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{


	GameEngineActor* Dest = _Other->GetActor();

	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage + UnitBase::SProUpgrade;

	return false;
}


void SwarmEffect::Update(float _DeltaTime)
{


	
	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&SwarmEffect::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);


}