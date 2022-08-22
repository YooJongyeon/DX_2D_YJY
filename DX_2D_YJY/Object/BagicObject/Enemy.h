#pragma once
class Enemy
{
public:
	Enemy(wstring file, Vector2 maxFrame, float speed);
	~Enemy();

	void CreateAction(wstring file, float speed);

	void Update();
	void Render();

	void Play(Vector2 pos);
	void End() { _isActive = false; }
	void Move();

	bool _isActive = false;
private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Action> _action;
	shared_ptr<Collider> _col;

	Vector2 _enemyPos = { 0.0f, 100.0f };
	Vector2 _maxFrame;
};

