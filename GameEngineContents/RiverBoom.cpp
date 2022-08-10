
#include "PreCompile.h"
#include "RiverBoom.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
RiverBoom::RiverBoom()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

RiverBoom::~RiverBoom()
{
	Death();
}

void RiverBoom::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void RiverBoom::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("ScarabE", FrameAnimation_DESC("ScarabE", 0.05f));
		Renderer->ChangeFrameAnimation("ScarabE");
		Renderer->AnimationBindEnd("ScarabE", &RiverBoom::AttEnd, this);
	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 128.0f, 128.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}
	m_Info.Dammage = 1.f;



}
bool RiverBoom::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{


	GameEngineActor* Dest = _Other->GetActor();

	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage;

	return true;
}

void RiverBoom::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&RiverBoom::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);


}