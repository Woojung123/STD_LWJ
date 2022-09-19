

#include "PreCompile.h"
#include "Plaegue.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
Plaegue::Plaegue()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

Plaegue::~Plaegue()
{
	Death();
}

void Plaegue::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void Plaegue::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("plaegue", FrameAnimation_DESC("plaegue", 0.05f));
		Renderer->ChangeFrameAnimation("plaegue");
		Renderer->AnimationBindEnd("plaegue", &Plaegue::AttEnd, this);
		Renderer->GetPixelData().MulColor.a = 0.5f;
	}

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 128.0f, 128.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}
	m_Info.Dammage = 1;



}

bool Plaegue::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	

	GameEngineActor* Dest = _Other->GetActor();
	
	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage + UnitBase::SZergUpgrade;

	return false;
}


void Plaegue::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&Plaegue::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);



}