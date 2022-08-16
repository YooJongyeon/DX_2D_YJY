#pragma once
class Creature
{
	enum HeadState
	{
		IDLE,
		IDLE_SHOT,

		ATTACK,
		ATTACK_SHOT,
	};

public:
	Creature();
	~Creature();

	void CreateActions();

	void Update();
	void Render();
	void PostRender();

	void SetPostion(float x, float y);
	void SetAnimation(HeadState aniState);
	void Attack(shared_ptr<class Character> character);

private:
	HeadState _aniState = IDLE;

	shared_ptr<Sprite> _Idle;
	shared_ptr<Sprite> _Attack;

	shared_ptr<Sprite> _ShpotFrontIdle;
	shared_ptr<Sprite> _ShpotAttack;

	vector<shared_ptr<Action>> _actions;
	vector<shared_ptr<Action>> _actionsAttack;

	Vector2 _maxFrame;


	float _runTime = 0.0f;
	float _destroyTime = 5.0f;
};

