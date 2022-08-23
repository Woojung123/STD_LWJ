

#include "PreCompile.h"
#include "Tileobject.h"


Tileobject::Tileobject()

{
}

Tileobject::~Tileobject()
{
}



void Tileobject::Start()
{

	GetTransform().SetLocalScale({ 1, 1, 1 });
	//{
	//	Renderer = CreateComponent<GameEngineTextureRenderer>();
	//	Renderer->SetTexture("Tile2.png");
	//	Renderer->ScaleToTexture();

	//}


	{
		Collision = CreateComponent<GameEngineCollision>();
		Collision->GetTransform().SetLocalScale({ 60.0f, 60.0f, 1.0f });
		Collision->ChangeOrder(OBJECTORDER::TileMap);
		
	}




}

void Tileobject::Update(float _DeltaTime)
{

	

	float4 WorldPos = GetTransform().GetWorldPosition();
	GetTransform().SetWorldPosition({ WorldPos.x , WorldPos.y , -79.f, WorldPos.w });


}

