#pragma once
class TestPlayer
{
	enum State
	{
		F_IDLE,
		B_IDLE,

		F_RUN,
		B_RUN,

		F_JUMP,
		B_JUMP
	};

	enum Direction
	{
		RIGHT,
		LEFT
	};

public:
	TestPlayer();
	~TestPlayer();


	void Update();
	void Render();
	void PostRender();

	void SetTile(vector<shared_ptr<Tile>>tiles) { _tile = tiles; }


	void SetPostion(float x, float y);
	void SetPlay(State stay);
	void Move();
	void SEltDLE();
	void Jumping();
	void BackJumping();
	void Gravity();
	void BackGravity();
	void FRunGravity();
	void BRunGravity();

	void Fire();
	void AttackMonsters(shared_ptr<class Creature> Enemy);
	void AttackGhost(shared_ptr<class Ghost> Ghost);

	shared_ptr<Collider> GetFidleColl() { return _FidleEnemy->GetColl(); }
	shared_ptr<Collider> GetFMoveColl() { return _FmoveEnemy->GetColl(); }
	shared_ptr<Collider> GetBidleColl() { return _BidleEnemy->GetColl(); }
	shared_ptr<Collider> GetBmoveColl() { return _BmoveEnemy->GetColl(); }
	shared_ptr<Collider> GetFjumpColl() { return _FjumpEnemy->GetColl(); }
	shared_ptr<Collider> GetBjumpColl() { return _BjumpEnemy->GetColl(); }

	shared_ptr<Transform> GetTransform() { return _FmoveEnemy->GetTransform(); }
	Vector2 GetPlayerPos() { return _PlayerPos; }

	shared_ptr<Players> GetPlayer() { return _FmoveEnemy; }

	shared_ptr<class Weapon>GetWeapon() { return _Weapon; }

	float _hp = 100.0f;
	float _weaponDamage = 0.08f;
	bool _isActive = false;
	
private:
	State _aniState = F_IDLE;
	Direction _direction = RIGHT;
	shared_ptr<Quad> _quad;
	shared_ptr<Players> _FidleEnemy;
	shared_ptr<Players> _FmoveEnemy;

	shared_ptr<Players> _BidleEnemy;
	shared_ptr<Players> _BmoveEnemy;

	shared_ptr<Players> _FjumpEnemy;
	shared_ptr<Players> _BjumpEnemy;

	shared_ptr<class Weapon> _Weapon;
	Vector2 _PlayerPos = {100.0f, 200.0f};

	Vector2 _maxFrame;

	vector<shared_ptr<Tile>> _tile;

	float _runTime = 0.0f;
	float _destroyTime = 5.0f;

	float _fGravutyPower = 3.0f;
	float _bGravutyPower = 3.0f;

	float _fRunGravutyPower = 3.0f;
	float _bRuneGravutyPower = 3.0f;

	float _jumpPower = 500.0f;
	float _BackjumpPower = 500.0f;

	float _gravity = 0.78f;

	float _fGravity = 0.48f;
	float _bGravity = 0.48f;

	float _fRunGravity = 0.78f;
	float _bRunbGravity = 0.78f;

	float _spead = 100.0f;

	bool _isfal = true;
	bool _backIsfal = true;

	bool _FRunIsfal = true;
	bool _BRunIsfal = true;

	bool _isJumping = false;
	bool _isBackJumping = false;

};

