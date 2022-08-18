#pragma once
class Player
{
public:
	enum State
	{
		GROUND,
		JUMPLNG,
	};

	Player();
	~Player();
	void Inif();
	void Update();
	void Render();

	void AttackMonsters(vector<shared_ptr<class Monster>> _monster);

private:
	void Move();
	void Aiming();
	void Fire();
	void Jump();

private:

	shared_ptr<Quad> _quad;
	shared_ptr<Collider> _collider;

	shared_ptr<class Revolver> _revolver;
	shared_ptr<Transform> _revolverTrans;

	vector<shared_ptr<class Bullet>> _bullet;

	int _poolCount = 30;

	float _jumpPower = 300.0f;
	float _gravity = 100.0f;
	bool _isJumping = false;

	State _state = GROUND;
};

