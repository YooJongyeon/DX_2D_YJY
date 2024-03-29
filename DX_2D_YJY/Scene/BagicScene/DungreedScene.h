#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	~DungreedScene();
	
	virtual void Inif();
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender();

	void PrevScene();

private:
	shared_ptr<Player> _player;
	shared_ptr<Quad> _angle;
	vector<shared_ptr<Monster>> _monster;

	shared_ptr<Sprite> _zelda;

	float _guiTest = 0.0f; 
	float _pos = 0.0f;

	shared_ptr<Action> _action;

	shared_ptr<Bulton> _button;

	int _monsterCount = 1;
	int curFrameX = 0;
	int curFrameY = 0;

};


