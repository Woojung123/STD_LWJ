#include "PreCompile.h"
#include "DroneS.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"DroneBullet.h"
#include "DroneSUI.h"

DroneS::DroneS()
	: Speed(50.0f)
	, Renderer(nullptr)
	, Reach(300.f)
	, TestUni(nullptr)
	, AttCheck(false)
	, AttTimeMax(0.4f)
	, AttTime(0.f)
	, ListLastCheck(false)
	, m_Dir({ 0 })
	, BAniChange(false)
	, BulletType(0)
	, AuraRenderer(nullptr)
	, MainUI(nullptr)

{
}

DroneS::~DroneS()
{
}

void DroneS::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("DroneMove12");

}


void DroneS::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
		Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });

		Renderer->CreateFrameAnimationFolder("DroneAttack0", FrameAnimation_DESC("DroneAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack1", FrameAnimation_DESC("DroneAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack2", FrameAnimation_DESC("DroneAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack3", FrameAnimation_DESC("DroneAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack4", FrameAnimation_DESC("DroneAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack5", FrameAnimation_DESC("DroneAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack6", FrameAnimation_DESC("DroneAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack7", FrameAnimation_DESC("DroneAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack8", FrameAnimation_DESC("DroneAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack9", FrameAnimation_DESC("DroneAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack10", FrameAnimation_DESC("DroneAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack11", FrameAnimation_DESC("DroneAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack12", FrameAnimation_DESC("DroneAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack13", FrameAnimation_DESC("DroneAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack14", FrameAnimation_DESC("DroneAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneAttack15", FrameAnimation_DESC("DroneAttack15", 0.1f));
		Renderer->CreateFrameAnimationFolder("DroneMove12", FrameAnimation_DESC("DroneMove12", 0.1f));


		Renderer->ChangeFrameAnimation("DroneMove12");

		Renderer->AnimationBindEnd("DroneAttack0", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack1", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack2", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack3", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack4", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack5", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack6", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack7", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack8", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack9", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack10", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack11", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack12", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack13", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack14", &DroneS::AttEnd, this);
		Renderer->AnimationBindEnd("DroneAttack15", &DroneS::AttEnd, this);




	}

	//{

	//	AuraRenderer = CreateComponent<GameEngineTextureRenderer>();
	//	AuraRenderer->CreateFrameAnimationFolder("aulora0", FrameAnimation_DESC("aulora0", 0.1f));
	//	AuraRenderer->ChangeFrameAnimation("aulora0");
	//	AuraRenderer->GetTransform().SetLocalScale({ 120.f,120.f,1.f });
	//	float4 RenderWorldPos = AuraRenderer->GetTransform().GetWorldPosition();

	//	AuraRenderer->GetTransform().SetWorldPosition(RenderWorldPos);


	//}
	{

		AuraRenderer = CreateComponent<GameEngineTextureRenderer>();
		AuraRenderer->CreateFrameAnimationFolder("Maelstorm", FrameAnimation_DESC("Maelstorm", 0.1f));
		AuraRenderer->ChangeFrameAnimation("Maelstorm");
		AuraRenderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		AuraRenderer->GetColorData().MulColor.a = 1.f;
		AuraRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-1.f });

		/*	float4 RenderWorldPos = AuraRenderer->GetTransform().GetWorldPosition();

			AuraRenderer->GetTransform().SetWorldPosition(RenderWorldPos);*/


	}

 

	MainUI = GetLevel()->CreateActor<DroneSUI>(OBJECTORDER::UI);

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);
		//Collision->Off();
	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select1.png");
		ClickRenderer->ScaleToTexture();
		ClickRenderer->GetTransform().SetLocalPosition({ 0.f,-5.f,1.f });
	}

	{
		AttRenderer = CreateComponent<GameEngineTextureRenderer>();
		AttRenderer->SetTexture("SelectAtt.png");
		AttRenderer->GetTransform().SetLocalScale({ 600.f,600.f,1.f });

	}



}

void DroneS::Update(float _DeltaTime)
{
	if (m_bClickCheck)
	{
		MainUI->On();
		ClickRenderer->On();
		AttRenderer->On();
	}
	else
	{
		MainUI->Off();
		ClickRenderer->Off();
		AttRenderer->Off();
	}
	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Monster);

	int Monsize = (int)Group.size();
	int MonCount = 0;

	auto	iter = Group.begin();
	auto	iterEnd = Group.end();

	for (; iter != iterEnd; ++iter)
	{
		GameEngineActor* TarGet = (*iter);
		float4 TarGetPos = TarGet->GetTransform().GetWorldPosition();
		float4 MyPos = GetTransform().GetWorldPosition();
		float4 Dist = MyPos - TarGetPos;
		float MonLen = Dist.Length();

		++MonCount;

		if (MonLen <= Reach)
		{

			if (!BAniChange)
			{
				m_Dir = (TarGetPos - MyPos);
				m_Dir.Normalize();

				ChangeAni(TarGetPos, MyPos);
				BAniChange = true;
			}

			if (AttCheck)
			{

				AttCheck = false;

				BAniChange = false;
				TestUni = GetLevel()->CreateActor<DroneBullet>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);
				break;
				
			}


			break;
		}


		if (MonCount == Monsize)
		{
			AttCheck = false;
			BAniChange = false;
			Renderer->ChangeFrameAnimation("DroneMove12");
			AttTime = 0.f;
			
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void DroneS::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("DroneAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("DroneAttack15");
	}


}
