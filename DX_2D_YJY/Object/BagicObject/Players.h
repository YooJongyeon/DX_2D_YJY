#pragma once
class Players
{
public:
	Players(wstring file, Vector2 maxFrame, float speed);
	~Players();

	void CreateAction(wstring file, float speed);

	void Update();
	void Render();

	void Play(Vector2 pos);
	void End() { _isActive = false; }
	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }
	shared_ptr<Collider> GetColl() { return _col; }
	shared_ptr<Action> GetAction() { return _action; }


	Vector2 _enemyPos = { 0.0f, 0.0f };
	bool _isActive = false;
	shared_ptr<Action> _action;
private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _col;
	shared_ptr<Transform> _FollowTrans;

	Vector2 _maxFrame;
};
