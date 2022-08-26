#pragma once
class TestScene : public Scene
{
public:
	TestScene();
	~TestScene();
	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender()override;

	void NextScene();
private:
	shared_ptr<TownMap> _townMap;
	shared_ptr<TileMap> _tileMap;
	shared_ptr<Creature> _creature;
	shared_ptr<Quad> _townSky;
	shared_ptr<Quad> _townLayer;
	shared_ptr<TestPlayer> _test;

	shared_ptr<Transform> _FollowTrans;

	shared_ptr<Quad> _angle;

	bool _timeStop = false;
};

