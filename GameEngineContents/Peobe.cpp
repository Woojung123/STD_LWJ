

#include "PreCompile.h"
#include "Peobe.h"
#include "GlobalContentsValue.h"
#include "MiniMapPlayer.h"
#include "ProbeSUI.h"



Peobe::Peobe()
	: Speed(150.0f)
	, Renderer(nullptr)
	, Reach(200.f)
	, AttCheck(false)
	, ListLastCheck(false)
{
}

Peobe::~Peobe()
{
}


void Peobe::AttEnd(const FrameAnimation_DESC& _Info)
{

}

void Peobe::Start()
{
	SoundPlayer = GameEngineSound::SoundPlayControl("ProbeSound.wav", false);
	SoundPlayer.PlaySpeed(1.f);
	SoundPlayer.Volume(0.5f);


	GetTransform().SetLocalScale({ 1, 1, 1 });
	{
		Renderer = CreateComponent<GameEngineTextureRenderer>();
		Renderer->GetTransform().SetLocalScale({ 32.f,32.f,1.f });
		Renderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });


		Renderer->CreateFrameAnimationFolder("ProbeMove0", FrameAnimation_DESC("ProbeMove0", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove1", FrameAnimation_DESC("ProbeMove1", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove2", FrameAnimation_DESC("ProbeMove2", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove3", FrameAnimation_DESC("ProbeMove3", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove4", FrameAnimation_DESC("ProbeMove4", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove5", FrameAnimation_DESC("ProbeMove5", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove6", FrameAnimation_DESC("ProbeMove6", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove7", FrameAnimation_DESC("ProbeMove7", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove8", FrameAnimation_DESC("ProbeMove8", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove9", FrameAnimation_DESC("ProbeMove9", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove10", FrameAnimation_DESC("ProbeMove10", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove11", FrameAnimation_DESC("ProbeMove11", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove12", FrameAnimation_DESC("ProbeMove12", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove13", FrameAnimation_DESC("ProbeMove13", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove14", FrameAnimation_DESC("ProbeMove14", 0.1f));
		Renderer->CreateFrameAnimationFolder("ProbeMove15", FrameAnimation_DESC("ProbeMove15", 0.1f));


		Renderer->ChangeFrameAnimation("ProbeMove12");


	}


	{
		ShadowRenderer = CreateComponent<GameEngineTextureRenderer>();
		ShadowRenderer->GetTransform().SetLocalScale({ 32.f,32.f,1.f });
		ShadowRenderer->GetTransform().SetLocalPosition({ 0.f,0.f,-2.f });


		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove0", FrameAnimation_DESC("ProbeMove0", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove1", FrameAnimation_DESC("ProbeMove1", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove2", FrameAnimation_DESC("ProbeMove2", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove3", FrameAnimation_DESC("ProbeMove3", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove4", FrameAnimation_DESC("ProbeMove4", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove5", FrameAnimation_DESC("ProbeMove5", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove6", FrameAnimation_DESC("ProbeMove6", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove7", FrameAnimation_DESC("ProbeMove7", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove8", FrameAnimation_DESC("ProbeMove8", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove9", FrameAnimation_DESC("ProbeMove9", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove10", FrameAnimation_DESC("ProbeMove10", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove11", FrameAnimation_DESC("ProbeMove11", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove12", FrameAnimation_DESC("ProbeMove12", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove13", FrameAnimation_DESC("ProbeMove13", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove14", FrameAnimation_DESC("ProbeMove14", 0.1f));
		ShadowRenderer->CreateFrameAnimationFolder("ProbeMove15", FrameAnimation_DESC("ProbeMove15", 0.1f));


		ShadowRenderer->ChangeFrameAnimation("ProbeMove12");

		ShadowRenderer->GetPixelData().MulColor.r = 0.f;
		ShadowRenderer->GetPixelData().MulColor.g = 0.f;
		ShadowRenderer->GetPixelData().MulColor.b = 0.f;
		ShadowRenderer->GetPixelData().MulColor.a = 0.5f;


		float4 SLocalPos = ShadowRenderer->GetTransform().GetLocalPosition();
		SLocalPos.y -= 5.f;
		SLocalPos.x -= 5.f;
		SLocalPos.z += 0.5f;
		ShadowRenderer->GetTransform().SetLocalPosition(SLocalPos);


	}

	MainUI = GetLevel()->CreateActor<ProbeSUI>(OBJECTORDER::UI);



	{
		Renderermineral = CreateComponent<GameEngineTextureRenderer>();
		Renderermineral->SetTexture("MiniMine.png");
		Renderermineral->ScaleToTexture();
		Renderermineral->GetTransform().SetLocalPosition({15.f, 0.f, -1.f });
		Renderermineral->Off();
	}



	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 25.0f, 25.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::Player);

	}

	{
		ClickRenderer = CreateComponent<GameEngineTextureRenderer>();
		ClickRenderer->SetTexture("Select1.png");
		ClickRenderer->ScaleToTexture();
		ClickRenderer->GetTransform().SetLocalPosition({ 0.f,-5.f,1.f });
	}



	MiniPlayUnit = GetLevel()->CreateActor<MiniMapPlayer>(OBJECTORDER::UI);



}

void Peobe::Update(float _DeltaTime)
{

	MiniPlayUnit->UnitPos = GetTransform().GetWorldPosition();

	


	if (m_bClickCheck)
	{
		MainUI->On();
		ClickRenderer->On();
		
	}
	else
	{
		if (m_bDragCheck)
		{
			MainUI->Off();
			ClickRenderer->On();
		
		}
		else
		{
			MainUI->Off();
			ClickRenderer->Off();
		
		}
	}


	float4 MyPos = GetTransform().GetWorldPosition();
	//bool MineralCheck = false;
	//bool MineralOn = false;

	//bool SleepTimecheck = false;
	//float Sleeptime = 0.f;

	//float4 MineralPos = { -1350.f, -240.f, 0.f };
	//float4 nexusPos = { -512.f,-240.f,0.f };
	if (MineralCheck)
	{


		if (!MineralOn)
		{

			if (!SleepTimecheck)
			{
				//Renderermineral->Off();

				if (DirCheck)
				{
					m_Dir = (MineralPos - MyPos);
					m_Dir.Normalize();

					ChangeAni(MineralPos, MyPos);
					DirCheck = false;
				}
				
				GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);


				if ((int)(MyPos.x + 10) > (int)(MineralPos.x) &&
					(int)(MyPos.x - 10) < (int)(MineralPos.x)
					&& (int)(MyPos.y - 10) < (int)(MineralPos.y)
					&& (int)(MyPos.y + 10) > (int)(MineralPos.y))
				{
					//MineralOn = !MineralOn;
					SleepTimecheck = true;

				}
			}
			else
			{
				Sleeptime += _DeltaTime;

				if (Sleeptime >= 3.f)
				{
					Renderermineral->On();
					SleepTimecheck = false;
					MineralOn = !MineralOn;
					Sleeptime = 0.f;
					DirCheck = true;
				}

			}
		

		}
		else
		{

			if (!SleepTimecheck)
			{


				if (DirCheck)
				{
					m_Dir = (nexusPos - MyPos);
					m_Dir.Normalize();

					ChangeAni(nexusPos, MyPos);
					DirCheck = false;
				}


				
				GetTransform().SetWorldMove(m_Dir * _DeltaTime * Speed);
				Renderermineral->On();

				if ((int)(MyPos.x + 10) > (int)(nexusPos.x) &&
					(int)(MyPos.x - 10) < (int)(nexusPos.x)
					&& (int)(MyPos.y - 10) < (int)(nexusPos.y)
					&& (int)(MyPos.y + 10) > (int)(nexusPos.y))
				{
					//MineralOn = !MineralOn;
					SleepTimecheck = true;

				}
			}
			else
			{
				Sleeptime += _DeltaTime;

				if (Sleeptime >= 1.f)
				{
					Renderermineral->Off();

					//µ· Αυ°΅ 
					m_MainStage->Player_Gold += 8.f;

					SleepTimecheck = false;
					MineralOn = !MineralOn;
					Sleeptime = 0.f;
					DirCheck = true;
				}

			}



		}



	}

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -19.f, WorldPos.w });


}


void Peobe::ChangeAni(float4 _Gopoint, float4 _WorldPos)
{

	float m_fAngle = acos(m_Dir.x);
	m_fAngle *= (180.f / 3.141592f);

	if (_Gopoint.y < _WorldPos.y)
		m_fAngle = 360.f - m_fAngle;




	if (m_fAngle >= 349.f || m_fAngle < 11.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove0");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove0");
	}

	if (m_fAngle >= 11.5 && m_fAngle < 34.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove1");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove1");
	}

	if (m_fAngle >= 34.f && m_fAngle < 56.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove2");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove2");
	}

	if (m_fAngle >= 56.5f && m_fAngle < 79.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove3");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove3");
	}

	if (m_fAngle >= 79.f && m_fAngle < 101.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove4");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove4");
	}

	if (m_fAngle >= 101.5f && m_fAngle < 124.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove5");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove5");
	}

	if (m_fAngle >= 124.f && m_fAngle < 146.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove6");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove6");
	}

	if (m_fAngle >= 146.5f && m_fAngle < 169.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove7");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove7");
	}

	if (m_fAngle >= 169.f && m_fAngle < 191.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove8");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove8");
	}

	if (m_fAngle >= 191.5f && m_fAngle < 214.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove9");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove9");
	}

	if (m_fAngle >= 214.f && m_fAngle < 236.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove10");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove10");
	}

	if (m_fAngle > 236.5f && m_fAngle < 259.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove11");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove11");
	}

	if (m_fAngle >= 259.f && m_fAngle < 281.5f) //Down
	{
		Renderer->ChangeFrameAnimation("ProbeMove12");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove12");
	}

	if (m_fAngle >= 281.5f && m_fAngle < 304.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove13");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove13");
	}

	if (m_fAngle >= 304.5f && m_fAngle < 326.5f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove14");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove14");
	}

	if (m_fAngle >= 326.5f && m_fAngle < 349.f)
	{
		Renderer->ChangeFrameAnimation("ProbeMove15");
		ShadowRenderer->ChangeFrameAnimation("ProbeMove15");
	}


}
