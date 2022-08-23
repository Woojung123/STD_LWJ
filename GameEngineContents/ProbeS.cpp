

#include "PreCompile.h"
#include "ProbeS.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"
#include"SwarmBullet.h"
#include "ProbeSUI.h"

ProbeS::ProbeS()
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
	, AuraRenderer(nullptr)
	, MainUI(nullptr)

{
}

ProbeS::~ProbeS()
{
}

void ProbeS::AttEnd(const FrameAnimation_DESC& _Info)
{
	AttCheck = true;
	Renderer->ChangeFrameAnimation("ProbeMove12");
	ShadowRenderer->ChangeFrameAnimation("ProbeMove12");
}


void ProbeS::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 32.f,32.f,1.f });
		Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });


		Renderer->CreateFrameAnimationFolder("ProbeMove0", FrameAnimation_DESC("ProbeMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove1", FrameAnimation_DESC("ProbeMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove2", FrameAnimation_DESC("ProbeMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove3", FrameAnimation_DESC("ProbeMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove4", FrameAnimation_DESC("ProbeMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove5", FrameAnimation_DESC("ProbeMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove6", FrameAnimation_DESC("ProbeMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove7", FrameAnimation_DESC("ProbeMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove8", FrameAnimation_DESC("ProbeMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove9", FrameAnimation_DESC("ProbeMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove10", FrameAnimation_DESC("ProbeMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove11", FrameAnimation_DESC("ProbeMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove12", FrameAnimation_DESC("ProbeMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove13", FrameAnimation_DESC("ProbeMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove14", FrameAnimation_DESC("ProbeMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove15", FrameAnimation_DESC("ProbeMove15", 0.1f));


		Renderer->ChangeFrameAnimation("ProbeMove12");


	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 32.f,32.f,1.f });
		ShadowRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });


		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove0", FrameAnimation_DESC("ProbeMove0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove1", FrameAnimation_DESC("ProbeMove1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove2", FrameAnimation_DESC("ProbeMove2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove3", FrameAnimation_DESC("ProbeMove3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove4", FrameAnimation_DESC("ProbeMove4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove5", FrameAnimation_DESC("ProbeMove5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove6", FrameAnimation_DESC("ProbeMove6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove7", FrameAnimation_DESC("ProbeMove7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove8", FrameAnimation_DESC("ProbeMove8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove9", FrameAnimation_DESC("ProbeMove9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove10", FrameAnimation_DESC("ProbeMove10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove11", FrameAnimation_DESC("ProbeMove11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove12", FrameAnimation_DESC("ProbeMove12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove13", FrameAnimation_DESC("ProbeMove13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove14", FrameAnimation_DESC("ProbeMove14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove15", FrameAnimation_DESC("ProbeMove15", 0.1f));


		ShadowRenderer->ChangeFrameAnimation("ProbeMove12");

		ShadowRenderer->GetColorData().MulColor.r = 0.f;
		ShadowRenderer->GetColorData().MulColor.g = 0.f;
		ShadowRenderer->GetColorData().MulColor.b = 0.f;
		ShadowRenderer->GetColorData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 5.f;
		SLocalPos.x -= 5.f;
		SLocalPos.z += 0.5f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);


	}





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
 
	MainUI = GetLevel()->CreateActor<ProbeSUI>(OBJECTORDER::UI);

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

void ProbeS::Update(float _DeltaTime)
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
			AttTime += _DeltaTime;
			m_Dir = (TarGetPos - MyPos);
			m_Dir.Normalize();

			ChangeAni(TarGetPos, MyPos);
			

			if (AttTime >= 2.f)
			{
				AttTime -= 2.f;

				BAniChange = false;

				TestUni = GetLevel()->CreateActor<SwarmBullet>(OBJECTORDER::Bullet);
				TestUni->GetTransform().SetWorldPosition(MyPos);
				TestUni->SetTarGet(TarGet);
				TestUni->m_Info.Dammage = 90;


			}


			break;
		}


		if (MonCount == Monsize)
		{

			AttTime = 0.f;
		}


	}


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });




}

void ProbeS::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove0");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove1");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove2");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove3");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove4");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove5");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove6");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove7");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove8");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove9");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove10");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove11");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("ProbeMove12");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove13");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove14");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove15");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove15");
	}


}
