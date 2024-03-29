#pragma once
class Action
{
public:
	struct Clip
	{
		Vector2 _startPos;
		Vector2 _size;
		shared_ptr<Texture> _texture;

		Clip(float x, float y, float w, float h, shared_ptr<Texture> texture)
			: _startPos({ x,y }), _size({ w,h }), _texture(texture)
		{}
	};

	enum Type
	{
		END,
		LOOP,
		PINPONG
	};

	Action(vector<Clip> clips, string name = "", Type type = LOOP, float speed = 0.1f);
	~Action();

	void Update();

	void Play();
	void Pause();
	void Stop();
	void Reset();

	void SetEndEvent(CallBack event) { _endEvent = event; }

	Clip GetCurClip() { return _clips[_curClipNum]; }
	bool IsPlay() { return _isPlay; }
	Action::Type GetAnimType() { return _repeatType; }

	string _actionName = "";

private:
	vector<Clip> _clips;
	Type _repeatType;
	bool _isPlay = true;

	UINT _curClipNum = 0;

	float _time = 0.0f;
	float _speed;

	bool _isReverse = false;

	CallBack _endEvent = nullptr;
};

