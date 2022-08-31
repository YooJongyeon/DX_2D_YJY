#pragma once
class Creature
{
	enum State
	{
		IDLE,
		IDLE_SHOT,
		LEFTIDLE,

		ATTACK,

		MOVE,
		LEFTMOVE,

	};

	enum Direction
	{
		NOME,
		LEFT,
		RIGHT,
	
		
	};


public:
	Creature();
	~Creature();


	void Update();
	void Render();
	void PostRender();

	void SetPostion(float x, float y);
	void SetPlay(State stay);
	void Move(Vector2 pos);

	void SEltDLE();
	void AttackPlayer(shared_ptr<class TestPlayer > player);
	void SetTravel(Vector2 tra);
	void SetPlayer(shared_ptr<class TestPlayer> players) { _players = players; }

	shared_ptr<Collider> GetCol1(){ return _moveEnemy->GetColl();}
	shared_ptr<Collider> GetCol2(){ return _leftMoveEnemy->GetColl();}


	shared_ptr<Enemy> GetMoveEnemy() { return _idleEnemy; }
	shared_ptr<Enemy> GetMoveEnemy2() { return _leftMoveEnemy; }
	
	float _hp = 100.0f;
	float _Damage = 0.01f;

	bool _isActive = false;

	State _aniState = IDLE;
private:
	Direction _dir = NOME;

	shared_ptr<Enemy> _idleEnemy;
	shared_ptr<Enemy> _moveEnemy;

	shared_ptr<Enemy> _leftIdleEnemy;
	shared_ptr<Enemy> _leftMoveEnemy;

	shared_ptr<Enemy> _attack;
;

	shared_ptr<class Weapon> _Weapon;
	Vector2 _maxFrame;
	Vector2 _creaturePos = {500.0f,300.0f};
	Vector2 _travel;

	shared_ptr<class TestPlayer> _players;

	float _speed = 50.0f;

	float _runTime = 0.0f;
	float _travelTime = 2.0f;
};

