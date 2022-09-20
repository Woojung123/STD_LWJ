

#include "PreCompile.h"
#include "EixtButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

EixtButton::EixtButton()
{
}

EixtButton::~EixtButton()
{
}


void EixtButton::Start()
{

	Renderer[0] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[0]->GetTransform().SetLocalScale({ 184.f,128.f,1.f });
	Renderer[0]->GetTransform().SetLocalPosition({ 200.f,-200.f,-10.f });
	Renderer[0]->CreateFrameAnimationFolder("ExitButton", FrameAnimation_DESC("MenuExit0", 0.1f));
	Renderer[0]->ChangeFrameAnimation("ExitButton");
	Renderer[0]->renderOption.Option01 = 1;


	Renderer[1] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[1]->GetTransform().SetLocalScale({ 216.f,136.f,1.f });
	Renderer[1]->GetTransform().SetLocalPosition({ 232.f,-195.f,-10.f });
	Renderer[1]->CreateFrameAnimationFolder("ExitButtonc", FrameAnimation_DESC("MenuExitCheck", 0.1f));
	Renderer[1]->ChangeFrameAnimation("ExitButtonc");
	Renderer[1]->renderOption.Option01 = 1;
	Renderer[1]->Off();

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 184.f,128.f,1.f });
		Collision->GetTransform().SetLocalPosition({ 200.f,-200.f,-10.f });
		Collision->ChangeOrder(OBJECTORDER::UI);


	}


	Font = CreateComponent<GameEngineFontRenderer>();
	// Font->ChangeCamera();
	Font->SetRenderingOrder(10000);
	Font->SetText("Exit", "Starcraft");
	Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.f });
	Font->SetSize(20);
	Font->SetScreenPostion({ 580, 410 });
	Font->ChangeCamera(CAMERAORDER::UICAMERA);
	Font->Off();

}

void EixtButton::Update(float _DeltaTime)
{
	timecheck += _DeltaTime;

	if (timecheck >= 2.f)
	{
		Font->On();
	}


	Renderer[1]->Off();


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&EixtButton::Collcheck, this, std::placeholders::_1, std::placeholders::_2)
	);

}


bool EixtButton::Collcheck(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Renderer[1]->On();
	/*if (true == GameEngineInput::GetInst()->IsDown("LChangeClick"))
	{

	}*/

	return true;

}
