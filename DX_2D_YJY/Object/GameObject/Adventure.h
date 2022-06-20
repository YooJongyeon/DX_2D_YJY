#pragma once
class Adventure
{
public:
	Adventure();
	~Adventure();

	void Update();
	void Render();

private:
	void Move();
	void Aiming();

private:

	shared_ptr<Texture> _texture;
	shared_ptr<class Revolver> _revolver;

	shared_ptr<Transform> _revolverTrans;
};

