#pragma once
class TileMap
{
public:
	TileMap();
	~TileMap();

	void TileCollision(shared_ptr<class Character> character);
	void Update();
	void Render();

	shared_ptr<Transform> GetTransform() { return _transform; }
private:
	vector<shared_ptr<Tile>> _tile;
	UINT _tileCount = 15;
	shared_ptr<Transform> _transform;
};

