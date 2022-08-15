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



};

