#include "framework.h"
#include "Tile.h"

Tile::Tile()
{
	_quad = make_shared<Quad>(L"Resource/Map/townAtlas3.png");
	_collider = make_shared<RectCollider>(Vector2(40,1));
	_collider->GetLocalPosition() = Vector2(-1.5f,10.0f);
	_quad->GetTransform()->GetScale().x += 2.0f;
	_collider->SetParent(_quad->GetTransform());
}

Tile::~Tile()
{
}

void Tile::Update()
{
	if (_isActive == false)
		return;
	_quad->Update();
	_collider->Update();
}

void Tile::Render()
{
	if (_isActive == false)
		return;
	_quad->Render();
	//_collider->Render();
	
}







