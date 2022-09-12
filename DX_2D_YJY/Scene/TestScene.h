#pragma once
class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();
	
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender()override;


private:
	shared_ptr<TownMap> _townMap;
	shared_ptr<TileMap> _tileMap;
	shared_ptr<Effect> _die;
	vector<shared_ptr<Creature>> _creature;
	vector<shared_ptr<Ghost>> _ghost;
	
	shared_ptr<TestPlayer> _test;
	shared_ptr<Transform> _FollowTrans;

	shared_ptr<Quad> _angle;

	int _monsterCount = 8;
	int _GostCount = 8;
	Vector2 _pos = { 0.0f,0.0f };
	Vector2 _gostPos = { 0.0f,0.0f };
	bool _timeStop = false;
};

