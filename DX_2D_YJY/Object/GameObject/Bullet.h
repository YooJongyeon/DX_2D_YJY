#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();

	shared_ptr<Transform> GetTransfom() { return _texture->GetTransform(); }
	void SetDirection(Vector2 dir);
	void SetPosition(const Vector2& pos) { _texture->GetTransform()->GetPos() = pos; }

	bool _isActive = false;

private:
	shared_ptr<Texture> _texture;
	Vector2 _direction;

	float _runTime = 0.0f;
	float _destroyTime = 3.0f;



};
