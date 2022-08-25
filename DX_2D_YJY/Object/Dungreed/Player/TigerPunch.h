#pragma once
class TigerPunch
{
public:
	TigerPunch();
	~TigerPunch();

	void Update();
	void Render();

	void GetPlay(Vector2 pos);
	shared_ptr<Transform> GetTransfom() { return _Weapon->GetTransform();; }
	void SetDirection(Vector2 dir);
	void SetPosition(const Vector2& pos) { _Weapon->GetTransform()->GetPos() = pos; }

	bool IsCollision(shared_ptr<Enemy> Enemy);

	bool _isActive = false;

private:

	shared_ptr<Weapon> _Weapon;
	shared_ptr<Collider> _collider;
	Vector2 _direction;

	float _runTime = 0.0f;
	float _destroyTime = 5.0f;

};

