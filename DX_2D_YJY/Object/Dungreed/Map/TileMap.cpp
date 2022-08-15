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
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.1f , WIN_HEIGHT * 0.05f };
			temp->_isActive = true;
			break;
		case 1:
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.26f , WIN_HEIGHT * 0.055f };
			temp->_isActive = true;
			break;
		case 2:
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.42f , WIN_HEIGHT * 0.05f };
			temp->_isActive = true;
			break;
		case 3:
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.57f , WIN_HEIGHT * 0.055f };
			temp->_isActive = true;
			break;
		case 4:
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.68f , WIN_HEIGHT * 0.05f };
			temp->_isActive = true;
			break;
		case 5:
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.77f , WIN_HEIGHT * 0.055f };
			temp->_isActive = true;
			break;
		case 6:
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.88f , WIN_HEIGHT * 0.05f };
			temp->_isActive = true;
			break;
		case 7:
			temp->GetTransform()->GetScale() *= 2.0f;
			temp->GetTransform()->GetPos() = { WIN_WIDTH * 0.97f , WIN_HEIGHT * 0.055f };
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

void TileMap::TileCollision(shared_ptr<class Character> character)
{
	for (auto & tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (tile->TileCollision(character))
		{
			tile->GetColl()->SetRed();
			character->_CharacterPos.y = tile->GetColl()->Top() + character->GetSprite()->GetHalfFrameSize().y - 5.0f;
			character->_CharacterPos.y = tile->GetColl()->Top() + character->GetSprite2()->GetHalfFrameSize().y - 5.0f;
			character->_CharacterPos.y = tile->GetColl()->Top() + character->GetSprite3()->GetHalfFrameSize().y - 5.0f;
			character->_CharacterPos.y = tile->GetColl()->Top() + character->GetSprite4()->GetHalfFrameSize().y - 5.0f;
			
			
		}
		else
		{
			tile->GetColl()->SetGreen();
		}
	
	}
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

