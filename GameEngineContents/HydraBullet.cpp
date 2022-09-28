#include "PreCompile.h"
#include "HydraBullet.h"

HydraBullet::HydraBullet() 
{
}

HydraBullet::~HydraBullet() 
{
}

void HydraBullet::Start()
{

	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });

		Renderer->CreateFrameAnimationFolder("HYAttack0", FrameAnimation_DESC("HYAttack0", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack1", FrameAnimation_DESC("HYAttack1", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack2", FrameAnimation_DESC("HYAttack2", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack3", FrameAnimation_DESC("HYAttack3", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack4", FrameAnimation_DESC("HYAttack4", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack5", FrameAnimation_DESC("HYAttack5", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack6", FrameAnimation_DESC("HYAttack6", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack7", FrameAnimation_DESC("HYAttack7", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack8", FrameAnimation_DESC("HYAttack8", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack9", FrameAnimation_DESC("HYAttack9", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack10", FrameAnimation_DESC("HYAttack10", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack11", FrameAnimation_DESC("HYAttack11", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack12", FrameAnimation_DESC("HYAttack12", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack13", FrameAnimation_DESC("HYAttack13", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack14", FrameAnimation_DESC("HYAttack14", 0.1f));
		Renderer->CreateFrameAnimationFolder("HYAttack15", FrameAnimation_DESC("HYAttack15", 0.1f));


		Renderer->AnimationBindEnd("HYAttack0", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack1", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack2", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack3", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack4", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack5", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack6", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack7", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack8", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack9", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack10", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack11", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack12", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack13", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack14", &HydraBullet::AttEnd, this);
		Renderer->AnimationBindEnd("HYAttack15", &HydraBullet::AttEnd, this);


		Renderer->ChangeFrameAnimation("HYAttack0");

	}



}

void HydraBullet::Update(float _DeltaTime)
{

	

	
}

void HydraBullet::AttEnd(const FrameAnimation_DESC& _Info)
{


	Death();


}

void HydraBullet::ChangeAni(float4 _Gopoint, float4 _WorldPos , float4 m_Dir)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("HYAttack0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("HYAttack2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("HYAttack4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("HYAttack6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("HYAttack8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("HYAttack10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("HYAttack12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("HYAttack14");
		
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("HYAttack15");
		
	}



}
