
#include "PreCompile.h"
#include "StartButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

StartButton::StartButton()
{
}

StartButton::~StartButton()
{
}


void StartButton::Start()
{

	Renderer[0] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[0]->GetTransform().SetLocalScale({ 260.f,176.f,1.f });
	Renderer[0]->GetTransform().SetLocalPosition({ -200.f,-150.f,-10.f });
	Renderer[0]->CreateFrameAnimationFolder("MenuMultiPlayer0", FrameAnimation_DESC("MenuMultiPlayer0", 0.1f));
	Renderer[0]->ChangeFrameAnimation("MenuMultiPlayer0");
	Renderer[0]->renderOption.Option01 = 1;


	Renderer[1] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[1]->GetTransform().SetLocalScale({ 264.f,148.f,1.f });
	Renderer[1]->GetTransform().SetLocalPosition({ -178.f,-147.f,-10.f });
	Renderer[1]->CreateFrameAnimationFolder("MenuMultiPlayerCheck0", FrameAnimation_DESC("MenuMultiPlayerCheck0", 0.1f));
	Renderer[1]->ChangeFrameAnimation("MenuMultiPlayerCheck0");
	Renderer[1]->renderOption.Option01 = 1;
	Renderer[1]->Off();

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 260.f,176.f,1.f });
		Collision->GetTransform().SetLocalPosition({ -200.f,-150.f,-10.f });
		Collision->ChangeOrder(OBJECTORDER::UI);


	}

	Font = CreateComponent<GameEngineFontRenderer>();
	// Font->ChangeCamera();
	Font->SetRenderingOrder(10000);
	Font->SetText("Multiplayer", "Starcraft");
	Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.f });
	Font->SetSize(20);
	Font->SetScreenPostion({ 80, 350 });
	Font->ChangeCamera(CAMERAORDER::UICAMERA);
	Font->Off();
	
}

void StartButton::Update(float _DeltaTime)
{

	timecheck += _DeltaTime;

	if (timecheck >= 2.f)
	{
		Font->On();
	}

	Renderer[1]->Off();



	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&StartButton::Collcheck, this, std::placeholders::_1, std::placeholders::_2)
	);



}

bool StartButton::Collcheck(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Renderer[1]->On();
	if (true == GameEngineInput::GetInst()->IsDown("LChangeClick"))
	{
		GEngine::ChangeLevel("Play");
	}

	return true;

}
