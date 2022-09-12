#pragma once
class Ghost
{
	enum State
	{
		MOVE,
		LEFTMOVE,
		ATTACK,
	


	};

	enum Direction
	{
		NOME,
		LEFT,
		RIGHT,


	};


public:
	Ghost();
	~Ghost();


	void Update();
	void Render();
	void PostRender();

	void SetPostion(Vector2 x, Vector2 y);
	void SetPlay(State stay);
	void Move(Vector2 pos);

	void AttackPlayer(shared_ptr<class TestPlayer > player);

	void SetPlayer(shared_ptr<class TestPlayer> players) { _players = players; }

	shared_ptr<Collider> GetCol1() { return _moveEnemy->GetColl(); }
	shared_ptr<Collider> GetCol2() { return _leftMoveEnemy->GetColl(); }

	shared_ptr<Enemy> GetMoveEnemy2() { return _leftMoveEnemy; }

	float _hp = 100.0f;
	float _Damage = 0.01f;

	bool _isActive = false;

	State _aniState = MOVE;
private:
	Direction _dir = NOME;

	shared_ptr<Enemy> _moveEnemy;
	shared_ptr<Enemy> _leftMoveEnemy;

	
	shared_ptr<Enemy> _attack;

	shared_ptr<class Weapon> _Weapon;
	shared_ptr<class TestPlayer> _players;

	Vector2 _maxFrame;
	Vector2 _creaturePos = { 500.0f,300.0f };


	float _speed = 50.0f;

};

