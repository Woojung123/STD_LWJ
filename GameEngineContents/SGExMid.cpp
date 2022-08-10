

#include "PreCompile.h"
#include "SGExMid.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
SGExMid::SGExMid()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

SGExMid::~SGExMid()
{
	Death();
}

void SGExMid::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void SGExMid::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 200.f,200.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });
		Renderer->GetColorData().MulColor.a = 0.5f;
		Renderer->CreateFrameAnimationFolder("Explosion_M", FrameAnimation_DESC("Explosion_M", 0.05f));
		Renderer->ChangeFrameAnimation("Explosion_M");
		Renderer->AnimationBindEnd("Explosion_M", &SGExMid::AttEnd, this);
	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 200.0f, 200.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}
	m_Info.Dammage = 1.f;



}

bool SGExMid::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{


	GameEngineActor* Dest = _Other->GetActor();

	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage;

	return true;
}
void SGExMid::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&SGExMid::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);


}