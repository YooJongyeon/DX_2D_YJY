#pragma once
class Player
{
public:
	Player();
	~Player();

	void Update();
	void Render();

	void AttackMonsters(vector<shared_ptr<class Monster>> _monster);

private:
	void Move();
	void Aiming();
	void Fire();

private:

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;

	shared_ptr<class Revolver> _revolver;
	shared_ptr<Transform> _revolverTrans;

	vector<shared_ptr<class Bullet>> _bullet;

	int _poolCount = 30;
};

