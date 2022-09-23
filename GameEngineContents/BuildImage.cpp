

#include "PreCompile.h"
#include "BuildImage.h"
#include"GameEngineBase/GameEngineRandom.h"

#include "Builder.h"

#include "GhostC.h"
#include "MarinC.h"
#include "ZealotC.h"
#include "CorsairC.h"
#include "HydraC.h"
#include "ZerglingC.h"
#include "GardianC.h"
#include "HighT.h"
#include "CannonB.h"
#include "UltraC.h"
#include "SunkenC.h"
#include "DarkTB.h"
#include "ArbitorB.h"
#include "MutalA.h"
#include "Arcon.h"
#include "River.h"
#include "Carrier.h"

#include "GhostS.h"
#include "DroneS.h"
#include "ProbeS.h"
#include "HydraS.h"

#include "TestUnit.h"



#include "Intercept.h"




BuildImage::BuildImage()
	: Speed(0.f)
	, Renderer(nullptr)
	, m_Dir({ 0 })
	, BAniChange(false)
	, m_Bulder(nullptr)
	, Buildingtype(0)
{
}

BuildImage::~BuildImage()
{
	Death();
}

void BuildImage::AttEnd(const FrameAnimation_DESC& _Info)
{


	BAniChange = true;



	if (Buildingtype == 1)
	{
		int RandomUnit = GameEngineRandom::MainRandom.RandomInt(0, 5);



		if (RandomUnit == 0)
		{
			HighT* TestUni = GetLevel()->CreateActor<HighT>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::HighTB;
		}

		if (RandomUnit == 1)
		{
			CannonB* TestUni = GetLevel()->CreateActor<CannonB>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::PhotoB;
		}
		if (RandomUnit == 2)
		{
			UltraC* TestUni = GetLevel()->CreateActor<UltraC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::UltraB;
		}

		if (RandomUnit == 3)
		{
			ArbitorB* TestUni = GetLevel()->CreateActor<ArbitorB>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ArbitorB;
		}

		if (RandomUnit == 4)
		{
			DarkTB* TestUni = GetLevel()->CreateActor<DarkTB>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::DarkTB;
		}

		if (RandomUnit == 5)
		{
			SunkenC* TestUni = GetLevel()->CreateActor<SunkenC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::SunkenB;
		}
	}
	else if (Buildingtype == 2)
	{


		int RandomUnit = GameEngineRandom::MainRandom.RandomInt(0, 4);



		if (RandomUnit == 0)
		{
			MutalA* TestUni = GetLevel()->CreateActor<MutalA>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::MutalA;
		}

		if (RandomUnit == 1)
		{
			GardianC* TestUni = GetLevel()->CreateActor<GardianC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::GardianA;
		}
		if (RandomUnit == 2)
		{
			Carrier* TestUni = GetLevel()->CreateActor<Carrier>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::CarrierA;



			for (int i = 0; i <= 7; ++i)
			{
				TestUni->m_Intercep[i] = GetLevel()->CreateActor<Intercept>(OBJECTORDER::Player);
				TestUni->m_Intercep[i]->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Intercep[i]->m_Info.Dammage = 30 + UnitBase::AProUpgrade;
				TestUni->m_Intercep[i]->Mycarrier = TestUni;
			}
		}

		if (RandomUnit == 3)
		{
			River* TestUni = GetLevel()->CreateActor<River>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::RiverA;
		}

		if (RandomUnit == 4)
		{
			Arcon* TestUni = GetLevel()->CreateActor<Arcon>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ArconA;



		}
	}
	else if (Buildingtype == 3)
	{

		int RandomUnit = GameEngineRandom::MainRandom.RandomInt(0, 3);
	

		if (RandomUnit == 0)
		{
			GhostS* TestUni = GetLevel()->CreateActor<GhostS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::GhostS;
		}

		if (RandomUnit == 1)
		{
			DroneS* TestUni = GetLevel()->CreateActor<DroneS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::DroneS;
		}
		if (RandomUnit == 2)
		{
			ProbeS* TestUni = GetLevel()->CreateActor<ProbeS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ProbeS;
		}

		if (RandomUnit == 3)
		{
			HydraS* TestUni = GetLevel()->CreateActor<HydraS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::HydraS;
		}




	}
	else
	{

		if (m_MainStage->Hellpertype == HellperUnitTYPE::NONE)
		{




			int RandomUnit = GameEngineRandom::MainRandom.RandomInt(0, 6);



			if (RandomUnit == 0)
			{
				GhostC* TestUni = GetLevel()->CreateActor<GhostC>(OBJECTORDER::Player);
				TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Type = UNITTYPE::GhostC;
				
			}

			if (RandomUnit == 1)
			{
				MarinC* TestUni = GetLevel()->CreateActor<MarinC>(OBJECTORDER::Player);
				TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Type = UNITTYPE::MarinC;
				
			}

			if (RandomUnit == 2)
			{
				ZealotC* TestUni = GetLevel()->CreateActor<ZealotC>(OBJECTORDER::Player);
				TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Type = UNITTYPE::ZealotC;
			
			}

			if (RandomUnit == 3)
			{
				CorsairC* TestUni = GetLevel()->CreateActor<CorsairC>(OBJECTORDER::Player);
				TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Type = UNITTYPE::CorsairC;
				
			}

			if (RandomUnit == 4)
			{
				HydraC* TestUni = GetLevel()->CreateActor<HydraC>(OBJECTORDER::Player);
				TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Type = UNITTYPE::HydraC;
				
			}

			if (RandomUnit == 5)
			{
				ZerglingC* TestUni = GetLevel()->CreateActor<ZerglingC>(OBJECTORDER::Player);
				TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Type = UNITTYPE::ZerglingC;
				
			}

			if (RandomUnit == 6)
			{
				TestUnit* TestUni = GetLevel()->CreateActor<TestUnit>(OBJECTORDER::Player);
				TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Type = UNITTYPE::DraC;
				
			}


		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::GhostC)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			GhostC* TestUni = GetLevel()->CreateActor<GhostC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::GhostC;
			

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::DragoonC)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			TestUnit* TestUni = GetLevel()->CreateActor<TestUnit>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::DraC;
			

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::MarineC)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			MarinC* TestUni = GetLevel()->CreateActor<MarinC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::MarinC;
			

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::ZealotC)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			ZealotC* TestUni = GetLevel()->CreateActor<ZealotC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ZealotC;
			

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::HydraC)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			HydraC* TestUni = GetLevel()->CreateActor<HydraC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::HydraC;
			

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::CorsairC)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			CorsairC* TestUni = GetLevel()->CreateActor<CorsairC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::CorsairC;
			

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::ZeaglingC)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			ZerglingC* TestUni = GetLevel()->CreateActor<ZerglingC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ZerglingC;
			

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::HighTB)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			HighT* TestUni = GetLevel()->CreateActor<HighT>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::HighTB;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::PhotoB)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			CannonB* TestUni = GetLevel()->CreateActor<CannonB>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::PhotoB;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::UltraB)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			UltraC* TestUni = GetLevel()->CreateActor<UltraC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::UltraB;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::ArbitorB)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			ArbitorB* TestUni = GetLevel()->CreateActor<ArbitorB>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ArbitorB;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::DarkTB)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			DarkTB* TestUni = GetLevel()->CreateActor<DarkTB>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::DarkTB;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::SunkenB)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			SunkenC* TestUni = GetLevel()->CreateActor<SunkenC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::SunkenB;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::MutalA)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			MutalA* TestUni = GetLevel()->CreateActor<MutalA>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::MutalA;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::GardianA)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			GardianC* TestUni = GetLevel()->CreateActor<GardianC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::GardianA;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::CarrierA)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			Carrier* TestUni = GetLevel()->CreateActor<Carrier>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::CarrierA;



			for (int i = 0; i <= 7; ++i)
			{
				TestUni->m_Intercep[i] = GetLevel()->CreateActor<Intercept>(OBJECTORDER::Player);
				TestUni->m_Intercep[i]->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
				TestUni->m_Intercep[i]->m_Info.Dammage = 30 + UnitBase::AProUpgrade;
				TestUni->m_Intercep[i]->Mycarrier = TestUni;
			}
		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::RiverA)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			River* TestUni = GetLevel()->CreateActor<River>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::RiverA;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::ArconA)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			Arcon* TestUni = GetLevel()->CreateActor<Arcon>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ArconA;
		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::GhostS)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			GhostS* TestUni = GetLevel()->CreateActor<GhostS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::GhostS;
		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::DroneS)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			DroneS* TestUni = GetLevel()->CreateActor<DroneS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::DroneS;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::ProbeS)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			ProbeS* TestUni = GetLevel()->CreateActor<ProbeS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ProbeS;

		}
		else if (m_MainStage->Hellpertype == HellperUnitTYPE::HydraS)
		{
			m_MainStage->Hellpertype = HellperUnitTYPE::NONE;
			HydraS* TestUni = GetLevel()->CreateActor<HydraS>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::HydraS;

		}

		
		
		


	}

}


void BuildImage::Start()
{


	SoundPlayer = GameEngineSound::SoundPlayControl("TowerMakeS.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.5f);




	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 64.f,64.f,1.f });
		//Renderer->GetTransform().SetWorldPosition({ -1050.f,370.f,0.f });

		Renderer->CreateFrameAnimationFolder("Feedback", FrameAnimation_DESC("Feedback", 0.05f));
		Renderer->ChangeFrameAnimation("Feedback");
		Renderer->AnimationBindEnd("Feedback", &BuildImage::AttEnd, this);
	}
}

void BuildImage::Update(float _DeltaTime)
{

	if (BAniChange)
		Death();


	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -100.f, WorldPos.w });

}