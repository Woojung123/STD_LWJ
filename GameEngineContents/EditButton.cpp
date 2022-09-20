

#include "PreCompile.h"
#include "EditButton.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>

EditButton::EditButton()
{
}

EditButton::~EditButton()
{
}


void EditButton::Start()
{

	
	Renderer[0] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[0]->GetTransform().SetLocalScale({ 160.f,140.f,1.f });
	Renderer[0]->GetTransform().SetLocalPosition({ 200.f,150.f,-10.f });
	Renderer[0]->CreateFrameAnimationFolder("MenuEditor0", FrameAnimation_DESC("MenuEditor0", 0.1f));
	Renderer[0]->ChangeFrameAnimation("MenuEditor0");
	Renderer[0]->renderOption.Option01 = 1;


	Renderer[1] = CreateComponent<GameEngineTextureRenderer>();
	Renderer[1]->GetTransform().SetLocalScale({ 204.f,132.f,1.f });
	Renderer[1]->GetTransform().SetLocalPosition({ 244.f,142.f,-10.f });
	Renderer[1]->CreateFrameAnimationFolder("MenuEditorCheck0", FrameAnimation_DESC("MenuEditorCheck0", 0.1f));
	Renderer[1]->ChangeFrameAnimation("MenuEditorCheck0");
	Renderer[1]->renderOption.Option01 = 1;
	Renderer[1]->Off();

	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 160.f,140.f,1.f });
		Collision->GetTransform().SetLocalPosition({ 200.f,150.f,-10.f });
		Collision->ChangeOrder(OBJECTORDER::UI);


	}

	Font = CreateComponent<GameEngineFontRenderer>();
	// Font->ChangeCamera();
	Font->SetRenderingOrder(10000);
	Font->SetText("Campaign Editor", "Starcraft");
	Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.f });
	Font->SetSize(20);
	Font->SetScreenPostion({ 500, 210 });
	Font->ChangeCamera(CAMERAORDER::UICAMERA);
	Font->Off();


}

void EditButton::Update(float _DeltaTime)
{

	timecheck += _DeltaTime;

	if (timecheck >= 2.f)
	{
		Font->On();
	}

	Renderer[1]->Off();


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&EditButton::Collcheck, this, std::placeholders::_1, std::placeholders::_2)
	);

	

}

bool EditButton::Collcheck(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	Renderer[1]->On();
	
	return true;
	
}
