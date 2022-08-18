#pragma once
class Object
{

public:
	Object(wstring file, Vector2 maxFrame, float speed);
	~Object();

	void CreateAction(wstring file, float speed);

	void Update();
	void Render();

	void Play(Vector2 pos);
	void End() { _isActive = false; }

	bool _isActive = false;
private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;

	Vector2 _maxFrame;
};

