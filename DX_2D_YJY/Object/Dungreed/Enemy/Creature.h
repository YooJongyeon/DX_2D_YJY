#pragma once
class Creature
{
	enum State
	{
		IDLE,
		IDLE_SHOT,

		ATTACK,
		ATTACK_SHOT,

		MOVE,
		MOVE_SHDT
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
	void SetTravel(Vector2 tra);
	void SetPlayer(shared_ptr<class TestPlayer> players) { _players = players; }
	
	
	shared_ptr<Collider> GetCol(){ return _idleEnemy->GetColl();}
	shared_ptr<Enemy> GetMoveEnemy() { return _moveEnemy; }
	

	bool _isActive = false;

private:
	State _aniState = IDLE;
	Direction _dir = NOME;

	shared_ptr<Enemy> _idleEnemy;
	shared_ptr<Enemy> _moveEnemy;
	Vector2 _maxFrame;
	Vector2 _creaturePos = {50.0f,50.0f};
	Vector2 _travel;

	shared_ptr<class TestPlayer> _players;

	float _speed = 100.0f;

	float _runTime = 0.0f;
	float _travelTime = 2.0f;
};

