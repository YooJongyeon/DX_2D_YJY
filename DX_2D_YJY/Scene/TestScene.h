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
	shared_ptr<Character> _character;
	shared_ptr<TownMap> _townMap;
	shared_ptr<TileMap> _tileMap;
	shared_ptr<Creature> _creature;

	shared_ptr<Transform> _FollowTrans;

	shared_ptr<Bulton> _button;

	bool _timeStop = false;
};

