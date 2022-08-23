#pragma once
class Bulton
{
public:
	enum BultonState
	{
		NONE,
		HOVER,
		CLICK
	};


	Bulton();
	~Bulton();

	void Update();
	void PostRender();

	void SetPosition(Vector2 pos);
	void SetScale(Vector2 scale);
	void SetText(string text);

	void SetState();
	void SetEvent(CallBack callBack) { _callback = callBack; }
	void SetEventParam(CallBackParam callBackParam, int param) 
	{ 
		_callbackParam = callBackParam;
		_param = param; 
	}
	
private:
	BultonState _state;

	shared_ptr<Quad> _quad;
	shared_ptr<RectCollider> _col;

	string _text;
	Vector2 _textPos = {0,0};

	shared_ptr<ButtonBuffer> _buttonBuffer;

	CallBack _callback;
	CallBackParam _callbackParam;
	int _param = 0;
};

