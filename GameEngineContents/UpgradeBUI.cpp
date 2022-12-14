
#include "PreCompile.h"
#include "UpgradeBUI.h"
#include "UnitBase.h"
#include "UpgradeB.h"
UpgradeBUI::UpgradeBUI() :
	m_UpC(nullptr)
	, Col_ProUpgrade(nullptr)
	, Col_TerUpgrade(nullptr)
	, Col_ZergUpgrade(nullptr)
{
}

UpgradeBUI::~UpgradeBUI()
{
}

void UpgradeBUI::Start()
{
	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("chamb.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ -170.f,-240.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Status_19.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 0.f,-240.f, -280.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);



	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->GetTransform().SetLocalScale({ 70.f,60.f,1.f });
		Renderer->CreateFrameAnimationFolder("Corsair", FrameAnimation_DESC("Corsair", 0.1f));
		Renderer->GetTransform().SetLocalPosition({ 155.f,-250.f, -280.f });
		Renderer->ChangeFrameAnimation("Corsair");


	}

	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Pro.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 255.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}

	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Ter.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 310.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);
	}


	{
		GameEngineUIRenderer* Renderer = CreateComponent<GameEngineUIRenderer>();
		Renderer->SetTexture("Zer.png");
		Renderer->ScaleToTexture();
		//Renderer->GetTransform().SetLocalScale({ 100, 20, 1 });
		Renderer->GetTransform().SetLocalPosition({ 370.f,-170.f, -250.f });
		Renderer->ChangeCamera(CAMERAORDER::UICAMERA);

	}

	{

		Col_ProUpgrade = CreateComponent<GameEngineCollision>();
		Col_ProUpgrade->GetTransform().SetLocalScale({ 36.f, 34.f, 1.f });
		Col_ProUpgrade->GetTransform().SetLocalPosition({ 255.f,-170.f, -250.f });
		Col_ProUpgrade->ChangeOrder(OBJECTORDER::UI);


	}

	{
		Col_TerUpgrade = CreateComponent<GameEngineCollision>();
		Col_TerUpgrade->GetTransform().SetLocalScale({ 36.f, 34.f, 1.f });
		Col_TerUpgrade->GetTransform().SetLocalPosition({ 310.f,-170.f, -250.f });
		Col_TerUpgrade->ChangeOrder(OBJECTORDER::UI);


	}

	{
		Col_ZergUpgrade = CreateComponent<GameEngineCollision>();
		Col_ZergUpgrade->GetTransform().SetLocalScale({ 36.f, 34.f, 1.f });
		Col_ZergUpgrade->GetTransform().SetLocalPosition({ 370.f,-170.f, -250.f });
		Col_ZergUpgrade->ChangeOrder(OBJECTORDER::UI);


	}

	

}



void UpgradeBUI::Update(float _DeltaTime)
{

	Col_ProUpgrade->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&UpgradeBUI::Col_Pro, this, std::placeholders::_1, std::placeholders::_2)
	);


	Col_TerUpgrade->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&UpgradeBUI::Col_Ter, this, std::placeholders::_1, std::placeholders::_2)
	);

	Col_ZergUpgrade->IsCollision(CollisionType::CT_OBB2D, OBJECTORDER::MouseUI, CollisionType::CT_OBB2D,
		std::bind(&UpgradeBUI::Col_Zerg, this, std::placeholders::_1, std::placeholders::_2)
	);

}

bool UpgradeBUI::Col_Pro(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	if (true == GameEngineInput::GetInst()->IsDown("LCUpClick"))
	{
		if (m_UpC->m_MainStage->Player_Gold < 50)
		{

			SoundPlayer = GameEngineSound::SoundPlayControl("NoMiNeral.wav", false);
			SoundPlayer.PlaySpeed(1.f);
			SoundPlayer.Volume(0.5f);

			return true;
		}

		m_UpC->m_MainStage->Player_Gold -= 50;

		SoundPlayer = GameEngineSound::SoundPlayControl("UpgradeSo.wav", false);
		SoundPlayer.PlaySpeed(1.f);
		SoundPlayer.Volume(0.5f);

		++UnitBase::BProUpgrade;
		m_UpC->m_bClickCheck = true;
	}

	return true;
}

bool UpgradeBUI::Col_Ter(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	if (true == GameEngineInput::GetInst()->IsDown("LCUpClick"))
	{
		if (m_UpC->m_MainStage->Player_Gold < 50)
		{
			SoundPlayer = GameEngineSound::SoundPlayControl("NoMiNeral.wav", false);
			SoundPlayer.PlaySpeed(1.f);
			SoundPlayer.Volume(0.5f);

			return true;
		}

		m_UpC->m_MainStage->Player_Gold -= 50;

		SoundPlayer = GameEngineSound::SoundPlayControl("UpgradeSo.wav", false);
		SoundPlayer.PlaySpeed(1.f);
		SoundPlayer.Volume(0.5f);

		m_UpC->m_bClickCheck = true;
		++UnitBase::BTerUpgrade;
	}

	return true;
}

bool UpgradeBUI::Col_Zerg(GameEngineCollision* _This, GameEngineCollision* _Other)
{

	if (true == GameEngineInput::GetInst()->IsDown("LCUpClick"))
	{
		if (m_UpC->m_MainStage->Player_Gold < 50)
		{
			SoundPlayer = GameEngineSound::SoundPlayControl("NoMiNeral.wav", false);
			SoundPlayer.PlaySpeed(1.f);
			SoundPlayer.Volume(0.5f);

			return true;
		}

		m_UpC->m_MainStage->Player_Gold -= 50;

		SoundPlayer = GameEngineSound::SoundPlayControl("UpgradeSo.wav", false);
		SoundPlayer.PlaySpeed(1.f);
		SoundPlayer.Volume(0.5f);

		++UnitBase::BZergUpgrade;
		m_UpC->m_bClickCheck = true;
	}

	return true;
}

