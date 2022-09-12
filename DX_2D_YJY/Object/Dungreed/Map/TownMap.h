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
	shared_ptr<Quad> _townSky;
	shared_ptr<Quad> _townLayer;
	shared_ptr<Quad> _townFloor;


	shared_ptr<Quad> _temple;
	shared_ptr<Quad> _templeFront;

	shared_ptr<Quad> _tavern;
	shared_ptr<Quad> _target;

	shared_ptr<Quad> _shop;


	shared_ptr<Quad> _blackSmith;
	shared_ptr<Quad> _blackSmithDisplay;


	Vector2 _leftBottom;
	Vector2 _rightTop;


};

