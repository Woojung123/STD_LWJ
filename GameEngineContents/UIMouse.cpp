


#include "PreCompile.h"
#include "UIMouse.h"

UIMouse::UIMouse() :
	Renderer(nullptr)
{
}

UIMouse::~UIMouse()
{
}

void UIMouse::Start()
{
	Renderer = CreateComponent<GameEngineUIRenderer>();
	Renderer->GetTransform().SetLocalScale({ 128.f,128.f,1.f });
	Renderer->GetTransform().SetLocalPosition({ 200.f,-200.f,-300.f });
	Renderer->CreateFrameAnimationFolder("Normal", FrameAnimation_DESC("Normal", 0.1f));
	Renderer->CreateFrameAnimationFolder("ScrollD", FrameAnimation_DESC("ScrollD", 0.1f));
	Renderer->CreateFrameAnimationFolder("ScrollL", FrameAnimation_DESC("ScrollL", 0.1f));
	Renderer->CreateFrameAnimationFolder("ScrollR", FrameAnimation_DESC("ScrollR", 0.1f));
	Renderer->CreateFrameAnimationFolder("ScrollU", FrameAnimation_DESC("ScrollU", 0.1f));
	Renderer->CreateFrameAnimationFolder("MagAlly", FrameAnimation_DESC("MagAlly", 0.1f));



	ShowCursor(false);

	Renderer->ChangeFrameAnimation("Normal");
	Renderer->ChangeCamera(CAMERAORDER::UICAMERA);

}


void UIMouse::Update(float _DeltaTime)
{


	float4 MousePos = GetLevel()->GetMainCamera()->GetMouseScreenPosition();
	MousePos.x -= 400.f;
	MousePos.y = -MousePos.y;
	MousePos.y += 300.f;
	MousePos.z = -300.f;



	if (MousePos.y >= 300)
	{
		MousePos.y = 300.f;
		Renderer->ChangeFrameAnimation("ScrollU");
	}
	else if (MousePos.y <= -300)
	{
		MousePos.y = -300.f;
		Renderer->ChangeFrameAnimation("ScrollD");
	}

	if (MousePos.x >= 400.f)
	{
		MousePos.x = 400.f;
		Renderer->ChangeFrameAnimation("ScrollR");
	}
	else if (MousePos.x <= -400.f)
	{
		MousePos.x = -400.f;
		Renderer->ChangeFrameAnimation("ScrollL");
	}
	

	if (MousePos.x >= -395.f && MousePos.x <= 395.f &&
		MousePos.y >= -295.f && MousePos.y <= 295.f)
	{
		Renderer->ChangeFrameAnimation("Normal");

	}


	Renderer->GetTransform().SetLocalPosition(MousePos);












}