#pragma once
class Weapon
{
public:
	Weapon(wstring file, Vector2 maxFrame, float speed);
	~Weapon();

	void CreateAction(wstring file, float speed);

	void Update();
	void Render();

	void Play();
	void SetDirection(Vector2 dir);
	void End() { _isActive = false; }

	void SetPlayer(shared_ptr<Transform> parent)
	{
		_sprite->GetTransform()->SetParent(parent);
	}
	void SetPosition(const Vector2& pos) { _sprite->GetTransform()->GetPos() = pos; }

	shared_ptr<Transform> GetTransform() { return _sprite->GetTransform(); }
	shared_ptr<Collider> GetColl() { return _col; }
	shared_ptr<Action> GetAction() { return _action; }

	bool _isActive = false;
private:

	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _col;
	shared_ptr<Action> _action;
	Vector2 _enemyPos;

	float _runTime = 0.0f;
	float _destroyTime = 5.0f;
	Vector2 _maxFrame;

};

