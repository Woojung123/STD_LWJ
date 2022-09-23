

#include "PreCompile.h"
#include "Recall.h"
#include "GlobalContentsValue.h"
#include <GameEngineCore/GameEngineLevel.h>



Recall::Recall()
	: Speed(1000.0f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, TarGet(nullptr)
	, m_dotDam(0.f)
	, BAniChange(false)
{
}

Recall::~Recall()
{
	Death();
}


void Recall::AttEnd(const FrameAnimation_DESC& _Info)
{
	BAniChange = true;

}


void Recall::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 100.f,100.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Recall", FrameAnimation_DESC("Recall", 0.05f));
		Renderer->ChangeFrameAnimation("Recall");

		Renderer->AnimationBindEnd("Recall", &Recall::AttEnd, this);
		Renderer->GetPixelData().MulColor.a = 0.8f;
	}

	m_Info.Dammage = 1;

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 100.f, 100.f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Bullet);


	}


}
bool Recall::MonsterCollision(GameEngineCollision* _This, GameEngineCollision* _Other)
{


	GameEngineActor* Dest = _Other->GetActor();
	m_Info.Dammage = 1;
	((UnitBase*)Dest)->m_Info.m_Hp -= m_Info.Dammage;

	return false;
}

void Recall::Update(float _DeltaTime)
{
	if (BAniChange)
		Death();



	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -45.f, WorldPos.w });


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Monster, CollisionType::CT_OBB2D,
		std::bind(&Recall::MonsterCollision, this, std::placeholders::_1, std::placeholders::_2)
	);



}