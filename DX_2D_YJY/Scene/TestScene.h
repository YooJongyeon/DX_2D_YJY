#pragma once
class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender()override;

	void NextScene();
private:
	shared_ptr<TownMap> _townMap;
	shared_ptr<TileMap> _tileMap;
	vector<shared_ptr<Creature>> _creature;
	vector<shared_ptr<Ghost>> _ghost;
	
	shared_ptr<TestPlayer> _test;
	shared_ptr<Transform> _FollowTrans;

	shared_ptr<Quad> _angle;

	int _monsterCount = 4;
	int _GostCount = 4;
	Vector2 _pos = { 0.0f,0.0f };
	Vector2 _gostPos = { 0.0f,0.0f };
	bool _timeStop = false;
};

