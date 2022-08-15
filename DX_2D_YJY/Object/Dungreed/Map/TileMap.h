#pragma once
class TileMap
{
public:
	TileMap();
	~TileMap();

	void TileCollision(shared_ptr<class Character> character);
	void Update();
	void Render();
private:
	vector<shared_ptr<Tile>> _tile;
	UINT _tileCount = 8;
};

