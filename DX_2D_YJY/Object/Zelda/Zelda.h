#pragma once
class Zelda
{
public:
	enum State
	{
		F_IDLE,
		L_IDLE,
		B_IDLE,
		R_IDLE,

		F_RUN,
		L_RUN,
		B_RUN,
		R_RUN,
	};

	Zelda();
	~Zelda();

	void CreateActions();

	void Update();
	void Render();
	void PostRender();

	void SetPostion(float x, float y);
	void SetAnimation(State aniState);

	void SetRightMessage() { _message = "Right RUN!!!"; };
	void SetBackMessage() { _message = "Back RUN!!!"; };
	void SetLeftMessage() { _message = "Left RUN!!!"; };
	void SetFrontMessage() { _message = "Front RUN!!!"; };

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }



private:
	State _aniState = F_IDLE;

	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Collider> _collider;

	string _message = "Hello";
};

