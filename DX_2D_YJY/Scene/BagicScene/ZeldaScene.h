#pragma once
class ZeldaScene : public Scene
{
public:
	ZeldaScene();
	virtual ~ZeldaScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

	void ZeldaMove();
	void NextScene();
private:
	shared_ptr<Zelda> _zelda;
	Vector2 _zeldaPos = { 0,0 };
	shared_ptr<Bulton> _button;
};

