

#include "PreCompile.h"
#include "Storm.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>



Storm::Storm()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, m_dotDam(0.f)
	, BAniChange(false)
{
}

Storm::~Storm()
{
	Death();
}


void Storm::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void Storm::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 224.f,224.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("storm", FrameAnimation_DESC("storm", 0.1f));
		Renderer->ChangeFrameAnimation("storm");

		Renderer->AnimationBindEnd("storm", &Storm::AttEnd, this);
	}

	m_Info.Dammage = 1;

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 224.0f, 224.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}


}
bool Storm::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{


	GameEngineActor* Dest = _Other->GetActor();

	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage;

	return true;
}

void Storm::Update(float _DeltaTime)
{
	if (BAniChange)
		Death();



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&Storm::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);



}