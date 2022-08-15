#include "framework.h"
#include "TownMap.h"

TownMap::TownMap()
{
	_townSky = make_shared<Quad>(L"Resource/Map/Town_BGL.png");
	_townSky->GetTransform()->GetScale().x *= 5.5f;
	_townSky->GetTransform()->GetScale().y *= 2.0f;
	_townSky->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.3f };

	_townLayer = make_shared<Quad>(L"Resource/Map/TownLayer_Day.png");
	_townLayer->GetTransform()->GetScale().x *= 3.5f;
	_townLayer->GetTransform()->GetScale().y *= 1.0f;
	_townLayer->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.3f };




}

TownMap::~TownMap()
{
}

void TownMap::Update()
{
	_townSky->Update();
	_townLayer->Update();

	
}

void TownMap::Render()
{
	_townSky->Render();
	_townLayer->Render();

	
}
