#pragma once
class MinMap
{
public:
	MinMap(Vector2 size);
	~MinMap();

	void Update();
	void SetRTV();
	void PostRender();

	void SetBackGround(Vector2 leftBottom, Vector2 rightTop) {_leftBottom = leftBottom, _rightTop = rightTop;}
	void SetPlayerPos(Vector2* playerPos) { _playerPos = playerPos; }

private:
	shared_ptr<RenderTarget> _rtv;
	shared_ptr<Quad> _targetTexture;
	shared_ptr<Quad> _miniPlayer;

	Vector2 _size = { 0,0 };

	Vector2 _leftBottom = { 0,0 };
	Vector2 _rightTop = { 0,0 };
	Vector2* _playerPos = nullptr;

};

