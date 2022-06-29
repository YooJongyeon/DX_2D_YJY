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
	shared_ptr<Texture> _angle;
	vector<shared_ptr<Monster>> _monster;

	float _guiTest = 0.0f; 
	float _x = 0.0f;

	int _monsterCount = 5;

};


