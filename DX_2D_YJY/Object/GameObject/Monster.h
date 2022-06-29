#pragma once
class Monster
{

public:
	Monster();
	~Monster();

	void Update();
	void Render();
	shared_ptr<Collider> GetCollider() { return _collider; }
	shared_ptr<Transform> GetTrasform() { return _texture->GetTransform(); }
	
	bool _isActive = false;

	float _hp = 100.0f;
private:

	shared_ptr<Texture> _texture;
	shared_ptr<Collider> _collider;

};
