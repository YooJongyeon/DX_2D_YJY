#include "framework.h"
#include "TownMap.h"

TownMap::TownMap()
{
	_townSky = make_shared<Quad>(L"Resource/Map/Town_BGL.png");
	_townSky->GetTransform()->GetScale().x *= 5.5f;
	_townSky->GetTransform()->GetScale().y *= 2.0f;
	_townSky->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };

	_townLayer = make_shared<Quad>(L"Resource/Map/TownLayer_Day.png");
	_townLayer->GetTransform()->GetScale().x *= 4.5f;
	_townLayer->GetTransform()->GetScale().y *= 3.0f;
	_townLayer->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.6f };

	_temple = make_shared<Quad>(L"Resource/Map/Temple.png");
	_temple->GetTransform()->GetPos() = { WIN_WIDTH * 0.1f  , WIN_HEIGHT * 0.25f };

	_templeFront = make_shared<Quad>(L"Resource/Map/TempleFront.png");
	_templeFront->GetTransform()->GetPos() = { WIN_WIDTH * 0.1f  , WIN_HEIGHT * 0.25f };

	_tavern = make_shared<Quad>(L"Resource/Map/Tavern.png");
	_tavern->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f  , WIN_HEIGHT * 0.35f };

	_target = make_shared<Quad>(L"Resource/Map/Target.png");
	_target->GetTransform()->GetPos() = { WIN_WIDTH * 1.5f  , WIN_HEIGHT * 0.3f };
		
	_shop = make_shared<Quad>(L"Resource/Map/Shop.png");
	_shop->GetTransform()->GetPos() = { WIN_WIDTH * 1.4f  , WIN_HEIGHT * 0.375f };

	_blackSmith = make_shared<Quad>(L"Resource/Map/BlackSmith.png");
	_blackSmith->GetTransform()->GetPos() = { WIN_WIDTH * 1.4f  , WIN_HEIGHT * 0.65f };

	_blackSmithDisplay = make_shared<Quad>(L"Resource/Map/BlackSmithDisplay.png");
	_blackSmithDisplay->GetTransform()->GetPos() = { WIN_WIDTH * 1.4f  , WIN_HEIGHT * 0.58f };



}

TownMap::~TownMap()
{
}

void TownMap::Update()
{
	_townSky->Update();
	_townLayer->Update();
	_temple->Update();
	_templeFront->Update();
	_tavern->Update();
	_target->Update();
	_shop->Update();
	_blackSmith->Update();
	_blackSmithDisplay->Update();

	
}

void TownMap::Render()
{
	_townSky->Render();
	_townLayer->Render();
	_temple->Render();
	_templeFront->Render();
	_tavern->Render();
	_target->Render();
	_shop->Render();
	_blackSmith->Render();
	_blackSmithDisplay->Render();

	
}
