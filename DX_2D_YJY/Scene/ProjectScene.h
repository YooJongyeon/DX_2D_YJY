#pragma once
class ProjectScene : public Scene
{
public:
	ProjectScene();
	~ProjectScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender()override;


private:
	shared_ptr<TownMap> _townMap;
	shared_ptr<TileMap> _tileMap;
	shared_ptr<Effect> _die;
	vector<shared_ptr<Creature>> _release;
	vector<shared_ptr<Ghost>> _ghost;

	shared_ptr<TestPlayer> _player;
	shared_ptr<Transform> _FollowTrans;

	shared_ptr<Quad> _angle;

	int _releaseCount = 10;
	int _GostCount = 10;
	Vector2 _pos = { 0.0f,0.0f };
	Vector2 _gostPos = { 0.0f,0.0f };
	bool _timeStop = false;
};

