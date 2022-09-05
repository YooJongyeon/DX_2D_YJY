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

		case 13:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.3f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;
		case 14:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.4f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;
		case 15:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;
		case 16:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.6f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;

		case 17:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.7f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;

		case 18:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.8f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;

		case 19:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.9f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;

		case 20:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.1f  , WIN_HEIGHT * 0.15f };
			temp->_isActive = true;
			break;

		case 21:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.3f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;

		case 22:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.4f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;

		case 23:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.5f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;

		case 24:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.6f  , WIN_HEIGHT * 0.27f };
			temp->_isActive = true;
			break;
		case 25:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.8f  , WIN_HEIGHT * 0.15f };
			temp->_isActive = true;
			break;

		case 26:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.05f  , WIN_HEIGHT * 0.4f };
			temp->_isActive = true;
			break;

		case 27:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.3f  , WIN_HEIGHT * 0.55f };
			temp->_isActive = true;
			break;
		case 28:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.4f  , WIN_HEIGHT * 0.55f };
			temp->_isActive = true;
			break;
		case 29:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f  , WIN_HEIGHT * 0.55f };
			temp->_isActive = true;
			break;
		case 30:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.6f  , WIN_HEIGHT * 0.55f };
			temp->_isActive = true;
			break;

		case 31:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.8f  , WIN_HEIGHT * 0.45f };
			temp->_isActive = true;
			break;

		case 32:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.35f  , WIN_HEIGHT * 0.55f };
			temp->_isActive = true;
			break;
		case 33:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.45f  , WIN_HEIGHT * 0.55f };
			temp->_isActive = true;
			break;
		case 34:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.55f  , WIN_HEIGHT * 0.55f };
			temp->_isActive = true;
			break;

		case 35:
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 1.1f  , WIN_HEIGHT * 0.6f };
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

