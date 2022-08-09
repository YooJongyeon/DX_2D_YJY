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
	void Set_ssWslah(bool up, bool down);
	void Attack();
	void Jumping();

	shared_ptr<Transform> GetTransform() { return _spriteFrontIdle->GetTransform(); }

	ssWslash Get_sswSlash();
	
	bool _isActive = false;
private:
	State _aniState = F_IDLE;

	Vector2 _CharacterPos =  CENTER;

	// 앞
	shared_ptr<Sprite> _spriteFrontIdle;
	shared_ptr<Sprite> _spriteFrontRun;

	// 뒤
	shared_ptr<Sprite> _spriteBackIdle;
	shared_ptr<Sprite> _spriteBackRun;

	// 점프
	shared_ptr<Sprite> _spriteJump;

	vector<shared_ptr<Action>> _actions;

	shared_ptr<Collider> _collider1;
	shared_ptr<Collider> _collider2;
	shared_ptr<Collider> _collider3;
	shared_ptr<Collider> _collider4;
	shared_ptr<Collider> _collider5;

	shared_ptr<class Weapon> _weapon;
	shared_ptr<class Weapon> _weapon2;
	shared_ptr<class Weapon> _weapon3;

	shared_ptr<Transform> _weaponTrans;
	shared_ptr<Transform> _weaponTrans2;
	shared_ptr<Transform> _weaponTrans3;

	

	float slashDigree;
	float ssWx;
	ssWslash slashstate;

	float _jumpPower = 200.0f;
	float _gravity = 150.0f;
	bool _isJumping = false;


	

};

