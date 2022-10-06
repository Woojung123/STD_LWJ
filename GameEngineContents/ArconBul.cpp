
#include "PreCompile.h"
#include "ArconBul.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>



ArconBul::ArconBul()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, m_dotDam(0.f)
	, BAniChange(false)
{
}

ArconBul::~ArconBul()
{
	Death();
}


void ArconBul::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;
	Renderer->Off();

}


void ArconBul::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 80.f,80.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("ArconHit", FrameAnimation_DESC("ArconHit", 0.1f));
		Renderer->ChangeFrameAnimation("ArconHit");

		Renderer->AnimationBindEnd("ArconHit", &ArconBul::AttEnd, this);
	}

	m_Info.Dammage = 1;

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 80.0f, 80.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}
	





}
bool ArconBul::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{


	GameEngineActor* Dest = _Other->GetActor();

	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage + UnitBase::AProUpgrade;

	return false;
}

void ArconBul::Update(float _DeltaTime)
{
	if (BAniChange)
		Death();


	

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&ArconBul::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);

}