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

public:
	Creature();
	~Creature();


	void Update();
	void Render();
	void PostRender();

	void SetPostion(float x, float y);
	void SetPlay(State stay);
	void Attack(shared_ptr<class Character> character);
	void Move();
	void SEltDLE();

private:
	State _aniState = IDLE;
	shared_ptr<Enemy> _idleEnemy;
	shared_ptr<Enemy> _moveEnemy;
	Vector2 _maxFrame;
	Vector2 _creaturePos = { 300.0f, 100.0f };

	float _runTime = 0.0f;
	float _destroyTime = 5.0f;
};

