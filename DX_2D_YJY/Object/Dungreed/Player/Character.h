#pragma once
class Character
{
public:
	enum State
	{
		F_IDLE,
		B_IDLE,

		F_RUN,
		B_RUN,

		F_JUMP,
	};

	enum JumpState
	{
		NONE,
		UP,
		DOWN
	};


	Character();
	~Character();

	void CreateActions();

	void Update();
	void Render();
	void PostRender();

	void SetPostion(float x, float y);
	void SetAnimation(State aniState);
	void ZeldMoveByKeyBoard();
	void SEltDLE();
	void Jumping();

	void SetTile(vector<shared_ptr<Tile>>tiles) { _tile = tiles; }
	bool TileCollision(shared_ptr<Tile> tile);
	shared_ptr<Transform> GetTransform() { return _spriteFrontIdle->GetTransform(); }

	shared_ptr<Sprite> GetSprite() { return _spriteFrontIdle; }
	shared_ptr<Sprite> GetSprite2() { return _spriteFrontRun; }
	shared_ptr<Sprite> GetSprite3() { return _spriteBackIdle; }
	shared_ptr<Sprite> GetSprite4() { return _spriteBackRun; }
	shared_ptr<Sprite> GetSprite5() { return _spriteJump; }

	shared_ptr<Collider> GetCollider() { return _frontIdleCollider; }
	shared_ptr<Collider> GetCollider2() { return _frontRunCollider; }
	shared_ptr<Collider> GetCollider3() { return _backIdleCollider; }
	shared_ptr<Collider> GetCollider4() { return _backRunCollider; }
	shared_ptr<Collider> GetCollider5() { return _jumpCollider; }

	ssWslash Get_sswSlash();
	
	bool _isActive = false;
	Vector2 _CharacterPos = { 0.0f, 100.0f };



private:
	State _aniState = F_IDLE;
	JumpState _jumpState = NONE;

	// 앞
	shared_ptr<Sprite> _spriteFrontIdle;
	shared_ptr<Sprite> _spriteFrontRun;

	// 뒤
	shared_ptr<Sprite> _spriteBackIdle;
	shared_ptr<Sprite> _spriteBackRun;

	// 점프
	shared_ptr<Sprite> _spriteJump;

	vector<shared_ptr<Action>> _actions;

	shared_ptr<Collider> _frontIdleCollider;
	shared_ptr<Collider> _frontRunCollider;
	shared_ptr<Collider> _backIdleCollider;
	shared_ptr<Collider> _backRunCollider;
	shared_ptr<Collider> _jumpCollider;

	shared_ptr<class Weapon> _weapon;
	shared_ptr<class Weapon> _weapon2;
	shared_ptr<class Weapon> _weapon3;
	shared_ptr<class Weapon> _weapon4;
	shared_ptr<class Weapon> _weapon5;

	shared_ptr<Transform> _weaponTrans;
	shared_ptr<Transform> _weaponTrans2;
	shared_ptr<Transform> _weaponTrans3;
	shared_ptr<Transform> _weaponTrans4;
	shared_ptr<Transform> _weaponTrans5;

	vector<shared_ptr<Tile>> _tile;

	float slashDigree;
	float ssWx;
	ssWslash slashstate;

	float _jumpPower = 150.0f;
	float _jumpTime = 0.0f;
	float _gravity = 9.8f;

	

	bool _isJumping = false;
	bool _isFrontMove = false;
	bool _isBackMove = false;



	

};

