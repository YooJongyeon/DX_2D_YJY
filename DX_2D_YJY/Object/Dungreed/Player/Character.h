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


	bool TileCollision(shared_ptr<Tile> tile);
	shared_ptr<Transform> GetTransform() { return _spriteFrontIdle->GetTransform(); }
	shared_ptr<RectCollider> GetCollider() { return _collider1; }

	ssWslash Get_sswSlash();
	
	bool _isActive = false;
	Vector2 _CharacterPos = { 0.0f, 0.0f };

private:
	State _aniState = F_IDLE;

	// 앞
	shared_ptr<Sprite> _spriteFrontIdle;
	shared_ptr<Sprite> _spriteFrontRun;

	// 뒤
	shared_ptr<Sprite> _spriteBackIdle;
	shared_ptr<Sprite> _spriteBackRun;

	// 점프
	shared_ptr<Sprite> _spriteJump;

	vector<shared_ptr<Action>> _actions;

	shared_ptr<RectCollider> _collider1;
	shared_ptr<RectCollider> _collider2;
	shared_ptr<RectCollider> _collider3;
	shared_ptr<RectCollider> _collider4;
	shared_ptr<RectCollider> _collider5;

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

	

	float slashDigree;
	float ssWx;
	ssWslash slashstate;

	float _jumpPower = 200.0f;
	float _gravity = 150.0f;
	bool _isJumping = false;




	

};

