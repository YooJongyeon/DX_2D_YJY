#include "framework.h"
#include "TileMap.h"

TileMap::TileMap()
{
	_tile.reserve(_tileCount);
	for (int i = 0; i < _tileCount; i++)
	{
		shared_ptr<Tile> temp = make_shared<Tile>();
		switch (i)
		{
		case 0:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.05f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;

		case 1:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.23f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;

		case 2:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.41f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;

		case 3:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.59f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;
		case 4:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.76f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;
		case 5:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.95f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;
		case 6:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.13f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;
		case 7:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.31f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;

		case 8:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.49f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;

		case 9:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.67f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;
		case 10:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.76f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;
		case 11:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.94f  , WIN_HEIGHT * 0.005f };
			temp->_isActive = true;
			break;
		case 12:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.15f  , WIN_HEIGHT * 0.15f };
			temp->_isActive = true;
			break;

		default:
			break;
		}
		_tile.push_back(temp);
	}
}

TileMap::~TileMap()
{
}


void TileMap::Update()
{
	for (auto& tile : _tile)
	{
		tile->Update();
	}
}

void TileMap::Render()
{

	for (auto& tile : _tile)
	{
		tile->Render();
	}
}

