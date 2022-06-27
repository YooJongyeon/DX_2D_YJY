#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	~DungreedScene();
	
	virtual void Update() override;

	virtual void Render() override;


private:
	shared_ptr<Adventure>_adventure;
	shared_ptr<Texture> _anagle;
	shared_ptr<Monster> _monster;

	float _guiTest = 0.0f; 

};


