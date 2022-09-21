#include "PreCompile.h"
#include "PlayNormal.h"
#include <GameEngineBase/GameEngineInput.h>
#include <GameEngineCore/GameEngineLevel.h>
#include "GlobalContentsValue.h"


#include "Builder.h"
#include "StageMain.h"
#include "StageMainCamera.h"

PlayNormal::PlayNormal():
	Sumdeta(0.f)

{
}

PlayNormal::~PlayNormal()
{
}



void PlayNormal::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });


	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->SetTexture("beacon2.png");
		Renderer->ScaleToTexture();
		Renderer->renderOption.Option01 = 5;
	
		

		fRenderer = CreateComponent<GameEngineTextureRenderer>();
		fRenderer->GetPixelData().MulColor.a = 0.f;
	}



	Font = CreateComponent<GameEngineFontRenderer>();
	// Font->ChangeCamera();
	Font->SetRenderingOrder(10000);
	Font->SetText("C", "Starcraft");
	Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.0 });
	Font->SetSize(25);
	Font->SetPositionMode(FontPositionMode::WORLD);
	Font->SetParent(fRenderer);
	fRenderer->GetTransform().SetLocalPosition({-30.f,50.f,0.f});


	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale(Renderer->GetTransform().GetLocalScale());
		Collision->ChangeOrder(OBJECTORDER::Life);
		
	}

	Sumdeta = 0.f;
}

void PlayNormal::Update(float _DeltaTime)
{

	if(!Deltacheck)
		Sumdeta += _DeltaTime * 2;
	else
		Sumdeta -= _DeltaTime * 2;



	if (Sumdeta >= 1.f)
	{
		Deltacheck = true;
	}
	if (Sumdeta <= 0.f)
	{
		Deltacheck = false;
		
	}

	Renderer->renderOption.alphaTime0 = Sumdeta;
	//Renderer->

	if (BiconType == 0)
	{
		Font->SetText("Hard", "Starcraft");
		Font->SetColor({ 0.0f, 0.0f, 1.0f, 1.0 });
	
	}
	else if (BiconType == 1)
	{
		Font->SetText("Easy", "Starcraft");
		Font->SetColor({ 0.0f, 1.0f, 0.0f, 1.0 });
		
	}
	else if (BiconType == 2)
	{
		Font->SetText("Hell", "Starcraft");
		Font->SetColor({ 1.0f, 0.0f, 0.0f, 1.0 });
		
	}


	Collision->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::Player, CollisionType::CT_OBB2D,
		std::bind(&PlayNormal::coll, this, std::placeholders::_1, std::placeholders::_2)
	);

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}

bool PlayNormal::coll(GameEngineCollision* _This, GameEngineCollision* _Other)
{
	if (BiconType == 0)
	{
		m_STMain->GameStartB = true;
		m_STMain->MonHpLevel = 1.5f;
		m_Builder->GetTransform().SetWorldPosition({ -1017.f,336.f ,0.f});
		m_Builder->Movecheck = false;
		m_Builder->Speed = 0.f;
		m_MainCamera->GetTransform().SetWorldPosition({ -1017.f,336.f ,0.f });;
	}
	else if (BiconType == 1)
	{
		m_STMain->GameStartB = true;
		m_STMain->MonHpLevel = 1.f;
		m_Builder->GetTransform().SetWorldPosition({ -1017.f,336.f ,0.f });
		m_Builder->Movecheck = false;
		m_Builder->Speed = 0.f;
		m_MainCamera->GetTransform().SetWorldPosition({ -1017.f,336.f ,0.f });;
	}
	else if (BiconType == 2)
	{
		m_STMain->GameStartB = true;
		m_STMain->MonHpLevel = 2.f;
		m_Builder->GetTransform().SetWorldPosition({ -1017.f,336.f ,0.f });
		m_Builder->Movecheck = false;
		m_Builder->Speed = 0.f;
		m_MainCamera->GetTransform().SetWorldPosition({ -1017.f,336.f ,0.f });;
	}

	return true;
}