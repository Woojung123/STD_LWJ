

#include "PreCompile.h"
#include "RiverTrail.h"
#include <GameEngineBase/GameEngineInput.h>
#include <iostream>
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineDefaultRenderer.h>
RiverTrail::RiverTrail()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
{
}

RiverTrail::~RiverTrail()
{

}

void RiverTrail::AttEnd(const FrameAnimation_DESC& _Info)
{
	Death();
	Renderer->Off();

}


void RiverTrail::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("ScarabM", FrameAnimation_DESC("ScarabM", 0.03f));
		Renderer->ChangeFrameAnimation("ScarabM");
		Renderer->AnimationBindEnd("ScarabM", &RiverTrail::AttEnd, this);
		Renderer->GetPixelData().MulColor.a = 0.5f;
	}
}

void RiverTrail::Update(float _DeltaTime)
{

	
		

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -50.f, WorldPos.w });

}