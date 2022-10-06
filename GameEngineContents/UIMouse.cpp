


#include "PreCompile.h"
#include "UIMouse.h"

UIMouse::UIMouse() :
	Renderer(nullptr)
	, UnitCol(false)
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

	Renderer->CreateFrameAnimationFolder("ScrollUL", FrameAnimation_DESC("ScrollUL", 0.1f));
	Renderer->CreateFrameAnimationFolder("ScrollUR", FrameAnimation_DESC("ScrollUR", 0.1f));
	Renderer->CreateFrameAnimationFolder("ScrollDL", FrameAnimation_DESC("ScrollDL", 0.1f));
	Renderer->CreateFrameAnimationFolder("ScrollDR", FrameAnimation_DESC("ScrollDR", 0.1f));


	Renderer->CreateFrameAnimationFolder("MagAlly", FrameAnimation_DESC("MagAlly", 0.1f));

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({1.f, 1.f, 1.f });
		Collision->ChangeOrder(OBJECTORDER::MouseUI);


	}
	//마우스 지우기
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


	if (UnitCol)
	{


			Renderer->ChangeFrameAnimation("MagAlly");


	}
	else
	{
		if (MousePos.y >= 300 && MousePos.x <= 400.f && MousePos.x >= -400.f)
		{
			MousePos.y = 300.f;
			Renderer->ChangeFrameAnimation("ScrollU");
		}
		else if (MousePos.y <= -300 && MousePos.x <= 400.f && MousePos.x >= -400.f)
		{
			MousePos.y = -300.f;
			Renderer->ChangeFrameAnimation("ScrollD");
		}

		else if (MousePos.x >= 400.f && MousePos.y <= 300 && MousePos.y >= -300)
		{
			MousePos.x = 400.f;
			Renderer->ChangeFrameAnimation("ScrollR");
		}
		else if (MousePos.x <= -400.f && MousePos.y <= 300 && MousePos.y >= -300)
		{
			MousePos.x = -400.f;
			Renderer->ChangeFrameAnimation("ScrollL");
		}


		else if (MousePos.y <= -300 && MousePos.x >= 400.f)
		{
			MousePos.y = -300.f;
			MousePos.x = 400.f;
			Renderer->ChangeFrameAnimation("ScrollDR");
		}

		else if (MousePos.y <= -300.f && MousePos.x <= -400.f)
		{
			MousePos.y = -300.f;
			MousePos.x = -400.f;
			Renderer->ChangeFrameAnimation("ScrollDL");
		}
		else if (MousePos.y >= 300 && MousePos.x >= 400.f)
		{
			MousePos.y = 300.f;
			MousePos.x = 400.f;
			Renderer->ChangeFrameAnimation("ScrollUR");
		}

		else if (MousePos.y >= 300.f && MousePos.x <= -400.f)
		{
			MousePos.y = 300.f;
			MousePos.x = -400.f;

			Renderer->ChangeFrameAnimation("ScrollUL");
		}



		if (MousePos.x >= -395.f && MousePos.x <= 395.f &&
			MousePos.y >= -295.f && MousePos.y <= 295.f)
		{
			Renderer->ChangeFrameAnimation("Normal");

		}

	}



	Renderer->GetTransform().SetLocalPosition(MousePos);
	Collision->GetTransform().SetLocalPosition(MousePos);











}