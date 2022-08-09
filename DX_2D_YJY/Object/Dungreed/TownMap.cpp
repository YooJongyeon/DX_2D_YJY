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

	_atlas = make_shared<Quad>(L"Resource/Map/townAtlas2.png");
	_atlas->GetTransform()->GetScale() *= 2.0f;
	_atlas->GetTransform()->GetPos() = { WIN_WIDTH * 0.1f , WIN_HEIGHT * 0.05f };

	_atlas2 = make_shared<Quad>(L"Resource/Map/townAtlas3.png");
	_atlas2->GetTransform()->GetScale() *= 2.0f;
	_atlas2->GetTransform()->GetPos() = { WIN_WIDTH * 0.26f , WIN_HEIGHT * 0.055f };

	_atlas3 = make_shared<Quad>(L"Resource/Map/townAtlas2.png");
	_atlas3->GetTransform()->GetScale() *= 2.0f;
	_atlas3->GetTransform()->GetPos() = { WIN_WIDTH * 0.42f , WIN_HEIGHT * 0.05f };

	_atlas4 = make_shared<Quad>(L"Resource/Map/townAtlas3.png");
	_atlas4->GetTransform()->GetScale() *= 2.0f;
	_atlas4->GetTransform()->GetPos() = { WIN_WIDTH * 0.57f , WIN_HEIGHT * 0.055f };

	_atlas5 = make_shared<Quad>(L"Resource/Map/townAtlas2.png");
	_atlas5->GetTransform()->GetScale() *= 2.0f;
	_atlas5->GetTransform()->GetPos() = { WIN_WIDTH * 0.68f , WIN_HEIGHT * 0.05f };

	_atlas6 = make_shared<Quad>(L"Resource/Map/townAtlas3.png");
	_atlas6->GetTransform()->GetScale() *= 2.0f;
	_atlas6->GetTransform()->GetPos() = { WIN_WIDTH * 0.77f , WIN_HEIGHT * 0.055f };

	_atlas7 = make_shared<Quad>(L"Resource/Map/townAtlas2.png");
	_atlas7->GetTransform()->GetScale() *= 2.0f;
	_atlas7->GetTransform()->GetPos() = { WIN_WIDTH * 0.88f , WIN_HEIGHT * 0.05f };

	_atlas8 = make_shared<Quad>(L"Resource/Map/townAtlas3.png");
	_atlas8->GetTransform()->GetScale() *= 2.0f;
	_atlas8->GetTransform()->GetPos() = { WIN_WIDTH * 0.97f , WIN_HEIGHT * 0.055f };





}

TownMap::~TownMap()
{
}

void TownMap::Update()
{
	_townSky->Update();
	_townLayer->Update();
	_townFloor->Update();
	_atlas->Update();
	_atlas2->Update();
	_atlas3->Update();
	_atlas4->Update();
	_atlas5->Update();
	_atlas6->Update();
	_atlas7->Update();
	_atlas8->Update();
	
}

void TownMap::Render()
{
	_townSky->Render();
	_townLayer->Render();
	_townFloor->Render();
	_atlas->Render();
	_atlas2->Render();
	_atlas3->Render();
	_atlas4->Render();
	_atlas5->Render();
	_atlas6->Render();
	_atlas7->Render();
	_atlas8->Render();

	
}
