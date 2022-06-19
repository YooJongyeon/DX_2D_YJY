#pragma once
class DungreedScene : public Scene
{
public:
	DungreedScene();
	~DungreedScene();
	
	virtual void Update() override;

	virtual void Render() override;

	void FireBullet();

private:
	shared_ptr<Texture> _adventure;
	shared_ptr<Texture> _revolver;
	shared_ptr<Texture> _anagle;

	vector<shared_ptr<Bullet>> _bulletPool;

};


