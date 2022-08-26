#include "framework.h"
#include "Tile.h"

Tile::Tile()
{
	_quad = make_shared<Quad>(L"Resource/Map/townAtlas2.png");
	_collider = make_shared<RectCollider>(_quad->GetHalfSize() * 1.0f);
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
	_collider->Render();
	
}







