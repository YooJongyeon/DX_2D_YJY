#pragma once
class CameraScene :public Scene
{
public:
	CameraScene();
	virtual ~CameraScene();
	
	virtual void Update() override;
	virtual void Render() override;
	virtual void PreRender() override;
	virtual void PostRender() override;

	void SavePos();
	void Test(int test);
	Vector2 LoadPos();

private:
	shared_ptr<Quad> _backGround;
	shared_ptr<Zelda> _zelda;
	shared_ptr<Transform> _zeldaFollowTrans;

	shared_ptr<Bulton> _bulton;
	shared_ptr<MinMap> _miniMap;
};

