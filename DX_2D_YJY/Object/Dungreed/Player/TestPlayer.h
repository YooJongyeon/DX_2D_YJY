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
	};


public:
	TestPlayer();
	~TestPlayer();


	void Update();
	void Render();
	void PostRender();

	void SetTile(vector<shared_ptr<Tile>>tiles) { _tile = tiles; }
	shared_ptr<Transform> GetTransform() { return _FidleEnemy->GetTransform(); }

	void SetPostion(float x, float y);
	void SetPlay(State stay);
	void Move();
	void SEltDLE();
	void Jumping();
	
	

private:
	State _aniState = F_IDLE;
	shared_ptr<Players> _FidleEnemy;
	shared_ptr<Players> _FmoveEnemy;

	shared_ptr<Players> _BidleEnemy;
	shared_ptr<Players> _BmoveEnemy;

	shared_ptr<Players> _FjumpEnemy;

	shared_ptr<class TigerPunch>_tigerPunch;

	Vector2 _maxFrame;
	Vector2 _PlayerPos = { 300.0f, 100.0f };

	vector<shared_ptr<Tile>> _tile;

	float _runTime = 0.0f;
	float _destroyTime = 5.0f;

	float _jumpPower = 200.0f;
	float _jumpTime = 0.0f;
	float _gravity = 9.8f;

	bool _isJumping = false;
	bool _isFrontMove = false;
	bool _isBackMove = false;
};

