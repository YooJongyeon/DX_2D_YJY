#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	~DungreedScene();
	
	virtual void Update() override;

	virtual void Render() override;


private:
	shared_ptr<Player> _player;
	shared_ptr<Quad> _angle;
	vector<shared_ptr<Monster>> _monster;

	shared_ptr<Sprite> _zelda;

	float _guiTest = 0.0f; 
	float _pos = 0.0f;

	int _monsterCount = 5;

};


