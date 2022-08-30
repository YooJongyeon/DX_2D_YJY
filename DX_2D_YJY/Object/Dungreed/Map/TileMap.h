#pragma once
class TileMap
{
public:
	TileMap();
	~TileMap();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }

	vector<shared_ptr<Tile>> GetTile() { return _tile; }
private:
	vector<shared_ptr<Tile>> _tile;
	UINT _tileCount = 30;
	shared_ptr<Transform> _transform;
};

