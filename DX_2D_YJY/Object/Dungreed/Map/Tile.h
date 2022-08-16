#pragma once
class Tile
{
public:
	Tile();
	~Tile();

	void Update();
	void Render();

	bool TileCollision(shared_ptr<class Character> character);
	shared_ptr<Transform> GetTransform() { return _quad->GetTransform(); }
	shared_ptr<Quad> GetQuad() { return _quad; }
	shared_ptr<Collider> GetColl() { return _collider; }
	bool _isActive = false;
	
private:
	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;

};

