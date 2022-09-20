
#include "PreCompile.h"
#include "DarkTile.h"
#include "StageMainCamera.h"
#include <GameEngineCore/GameEngineLevel.h>
#include <GameEngineCore/GameEngineTextureRenderer.h>


DarkTile::DarkTile()
{
}

DarkTile::~DarkTile()
{
}


void DarkTile::Start()
{

	
}
void DarkTile::Update(float _DeltaTime)
{

	std::list<GameEngineActor*> Group = GetLevel()->GetGroup(OBJECTORDER::Player);

	auto	iter = Group.begin();
	auto	iterEnd = Group.end();
	float4 MyPos = GetTransform().GetWorldPosition();


	for (; iter != iterEnd; ++iter)
	{
		float4 Playerpos = (*iter)->GetTransform().GetWorldPosition();
		float4 Dist = MyPos - Playerpos;
		float Len = Dist.Length();


		if (Len <= 100.f)
		{
			Tilestate = 2;
			Tilealpha = 0.5f;
		}
		else
		{
			if (Tilealpha = 0.5f)
			{
				Tilestate = 1;
			}
			else if (Tilealpha = 1.f)
			{
				Tilestate = 0;
			}
		}


	}

	float4 Dummy = MyPos - M_Camera->GetTransform().GetWorldPosition();
	Dummy.x -= 400.f;
	Dummy.y += 300.f;

	ScreenPos = Dummy;



}