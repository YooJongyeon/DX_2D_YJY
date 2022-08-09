#pragma once
class TownMap
{
public:
	TownMap();
	~TownMap();

	void Update();
	void Render();

	shared_ptr<Quad> GetTrasform() { return _townSky; }
private:
	shared_ptr<Quad> _townLayer;
	shared_ptr<Quad> _townFloor;
	shared_ptr<Quad> _townSky;
	shared_ptr<Quad> _atlas;
	shared_ptr<Quad> _atlas2;
	shared_ptr<Quad> _atlas3;
	shared_ptr<Quad> _atlas4;
	shared_ptr<Quad> _atlas5;
	shared_ptr<Quad> _atlas6;
	shared_ptr<Quad> _atlas7;
	shared_ptr<Quad> _atlas8;

};

