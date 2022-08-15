#include "framework.h"
#include "TownMap.h"

TownMap::TownMap()
{
	_townSky = make_shared<Quad>(L"Resource/Map/Town_BGL.png");
	_townSky->GetTransform()->GetScale() *= 1.5f;
	_townSky->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.3f };

	_townLayer = make_shared<Quad>(L"Resource/Map/TownLayer_Day.png");
	_townLayer->GetTransform()->GetScale() *= 1.5f;
	_townLayer->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.3f };

	_townFloor = make_shared<Quad>(L"Resource/Map/TownFloor.png");
	_townFloor->GetTransform()->GetScale() *= 0.2f;
	_townFloor->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.27f };


}

TownMap::~TownMap()
{
}

void TownMap::Update()
{
	_townSky->Update();
	_townLayer->Update();
	_townFloor->Update();
	
}

void TownMap::Render()
{
	_townSky->Render();
	_townLayer->Render();
	_townFloor->Render();
	
}
