

#include "PreCompile.h"
#include "MouseEff.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
MouseEff::MouseEff()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

MouseEff::~MouseEff()
{
	Death();
}

void MouseEff::AttEnd(const FrameAnimation_DESC& _Info)
{
	Death();
	Renderer->Off();
}


void MouseEff::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 44.f,28.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Click", FrameAnimation_DESC("Click", 0.05f));
		Renderer->ChangeFrameAnimation("Click");
		Renderer->AnimationBindEnd("Click", &MouseEff::AttEnd, this);
	}
}

void MouseEff::Update(float _DeltaTime)
{




	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}