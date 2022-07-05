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

	void Move();

	void SetF_RUN() { _actions[State::F_RUN]->Play(); }
	void SetL_RUN() { _actions[State::L_RUN]->Play(); }
	void SetB_RUN() { _actions[State::B_RUN]->Play(); }
	void SetR_RUN() { _actions[State::R_RUN]->Play(); }

	void SetF_IDLE() { _actions[State::F_IDLE]->Play(); }
	void SetL_IDLE() { _actions[State::L_IDLE]->Play(); }
	void SetB_IDLE() { _actions[State::B_IDLE]->Play(); }
	void SetR_IDLE() { _actions[State::R_IDLE]->Play(); }





private:
	State _aniState = F_IDLE;

	shared_ptr<Sprite> _sprite;
	vector<shared_ptr<Action>> _actions;
	shared_ptr<Collider> _collider;

	string _message = "Hello";
};

