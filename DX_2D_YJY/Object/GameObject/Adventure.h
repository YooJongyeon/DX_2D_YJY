#pragma once
class Adventure
{
public:
	Adventure();
	~Adventure();

	void Update();
	void Render();

private:
	void Move();
	void Aiming();
	void Fire();

private:

	shared_ptr<Texture> _texture;
	shared_ptr<Collider> _collider;

	shared_ptr<class Revolver> _revolver;
	shared_ptr<Transform> _revolverTrans;

	vector<shared_ptr<class Bullet>> _bullet;

	int _poolCount = 30;
};

