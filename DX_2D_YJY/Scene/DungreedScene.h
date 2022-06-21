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

	float _guiTest;

};


