

#include "PreCompile.h"
#include "SingleButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

SingleButton::SingleButton()
{
}

SingleButton::~SingleButton()
{
}


void SingleButton::Start()
{

	Renderer[0] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[0]->GetTransform().SetLocalScale({ 320.f,116.f,1.f });
	Renderer[0]->GetTransform().SetLocalPosition({ -250.f,150.f,-10.f });
	Renderer[0]->CreateFrameAnimationFolder("MenuSinglePlayer0", FrameAnimation_DESC("MenuSinglePlayer0", 0.1f));
	Renderer[0]->ChangeFrameAnimation("MenuSinglePlayer0");
	Renderer[0]->renderOption.Option01 = 1;


	Renderer[1] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[1]->GetTransform().SetLocalScale({ 252.f,124.f,1.f });
	Renderer[1]->GetTransform().SetLocalPosition({ -250.f,82.f,-10.f });
	Renderer[1]->CreateFrameAnimationFolder("MenuSinglePlayerCheck0", FrameAnimation_DESC("MenuSinglePlayerCheck0", 0.1f));
	Renderer[1]->ChangeFrameAnimation("MenuSinglePlayerCheck0");
	Renderer[1]->renderOption.Option01 = 1;
	Renderer[1]->Off();

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 320.f,116.f,1.f });
		Collision->GetTransform().SetLocalPosition({ -250.f,150.f,-10.f });
		Collision->ChangeOrder(OBJECTORDER::UI);


	}


	Font = CreateComponent<GameEngineFontRenderer>();
	// Font->ChangeCamera();
	Font->SetRenderingOrder(10000);
	Font->SetText("Single Player", "Starcraft");
	Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.f });
	Font->SetSize(20);
	Font->SetScreenPostion({ 80, 210 });
	Font->ChangeCamera(CAMERAORDER::UICAMERA);
	Font->Off();


}

void SingleButton::Update(float _DeltaTime)
{
	timecheck += _DeltaTime;

	if (timecheck >= 2.f)
	{
		Font->On();
	}

	Renderer[1]->Off();


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&SingleButton::Collcheck, this, std::placeholders::_1, std::placeholders::_2)
	);



}

bool SingleButton::Collcheck(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Renderer[1]->On();
	

	return true;

}
