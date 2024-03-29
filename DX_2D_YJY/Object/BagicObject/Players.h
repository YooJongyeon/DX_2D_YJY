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
	shared_ptr<Collider> GetTileEventColl() { return _eventCol; }
	shared_ptr<Collider> GetColl() { return _col; }
	shared_ptr<Action> GetAction() { return _action; }
	shared_ptr<Sprite> GetSprite() { return _sprite; }

	float _hp = 100.0f;
	Vector2 _enemyPos;
	bool _isActive = false;
private:
	shared_ptr<Sprite> _sprite;
	shared_ptr<Collider> _col;
	shared_ptr<Collider> _eventCol;
	shared_ptr<Action> _action;
	Vector2 _maxFrame;

	
	bool _isPass = false;
	bool _onTile = false;
};

