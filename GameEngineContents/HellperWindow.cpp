#include "PreCompile.h"
#include "HellperWindow.h"
#include "StageMain.h"
#include <GameEngineCore/GameEngineFolderTexture.h>
#include <GameEngineCore/GameEngineCoreDebug.h>

HellperWindow::HellperWindow()
{
}

HellperWindow::~HellperWindow()
{
}

void HellperWindow::Initialize(GameEngineLevel* _Level)
{
}

void HellperWindow::OnGUI(GameEngineLevel* _Level, float _DeltaTime)
{
	ImGui::Text("Unit Select");

	//c
	if (true == ImGui::Button("GhostC"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::GhostC;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("DragoonC"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::DragoonC;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("MarinC"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::MarineC;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("ZealotC"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::ZealotC;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("HydraC"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::HydraC;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("CorsairC"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::CorsairC;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("ZerglingC"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::ZeaglingC;
	}


	ImGui::NewLine();



	//b

	if (true == ImGui::Button("HighTB"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::HighTB;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("PhotoB"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::PhotoB;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("UltraB"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::UltraB;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("ArbitorB"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::ArbitorB;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("DarkTB"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::DarkTB;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("SunkenB"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::SunkenB;
	}
	ImGui::NewLine();



	//a


	if (true == ImGui::Button("MutalA"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::MutalA;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("GardianA"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::GardianA;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("CarrierA"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::CarrierA;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("RiverA"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::RiverA;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("ArconA"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::ArconA;
	}





	ImGui::NewLine();



	if (true == ImGui::Button("GhostS"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::GhostS;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("DroneS"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::DroneS;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("ProbeS"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::ProbeS;
	}
	ImGui::SameLine();
	if (true == ImGui::Button("HydraS"))
	{
		m_MainSt->Hellpertype = HellperUnitTYPE::HydraS;
	}




	ImGui::NewLine();

}

