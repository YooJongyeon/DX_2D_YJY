#pragma once
class TownMap
{
public:
	TownMap();
	~TownMap();

	void Update();
	void Render();

	shared_ptr<Quad> GetTrasform() { return _townSky; }

	Vector2& GetLeftBottom() { return _leftBottom; }
	Vector2& GetRightTop() { return _rightTop; }
private:
	shared_ptr<Quad> _townLayer;
	shared_ptr<Quad> _townFloor;
	shared_ptr<Quad> _townSky;

	Vector2 _leftBottom;
	Vector2 _rightTop;


};

