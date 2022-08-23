

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

		int RandomUnit = GameEngineRandom::MainRandom.RandomInt(0, 6);



		if (RandomUnit == 0)
		{
			GhostC* TestUni = GetLevel()->CreateActor<GhostC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::GhostC;
			m_Bulder->m_GhostC += 1;
		}

		if (RandomUnit == 1)
		{
			MarinC* TestUni = GetLevel()->CreateActor<MarinC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::MarinC;
			m_Bulder->m_MarinC += 1;
		}

		if (RandomUnit == 2)
		{
			ZealotC* TestUni = GetLevel()->CreateActor<ZealotC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ZealotC;
			m_Bulder->m_ZealotC += 1;
		}

		if (RandomUnit == 3)
		{
			CorsairC* TestUni = GetLevel()->CreateActor<CorsairC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::CorsairC;
			m_Bulder->m_CorsairC += 1;
		}

		if (RandomUnit == 4)
		{
			HydraC* TestUni = GetLevel()->CreateActor<HydraC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::HydraC;
			m_Bulder->m_HydraC += 1;
		}

		if (RandomUnit == 5)
		{
			ZerglingC* TestUni = GetLevel()->CreateActor<ZerglingC>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::ZerglingC;
			m_Bulder->m_ZerglingC += 1;
		}

		if (RandomUnit == 6)
		{
			TestUnit* TestUni = GetLevel()->CreateActor<TestUnit>(OBJECTORDER::Player);
			TestUni->GetTransform().SetWorldPosition(GetTransform().GetWorldPosition());
			TestUni->m_Type = UNITTYPE::DraC;
			m_Bulder->m_DraC += 1;
		}


	}





	


}


void BuildImage::Start()
{

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