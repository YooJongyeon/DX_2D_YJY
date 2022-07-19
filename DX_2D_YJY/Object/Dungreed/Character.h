#pragma once
class Character
{
public:
	enum State
	{
		R_IDLE,
		L_IDLE,

		L_RUN,
		R_RUN,
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


	
	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }





private:
	State _aniState = R_IDLE;

	Vector2 _CharacterPos = { 0,0 };
	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Collider> _collider;



};

