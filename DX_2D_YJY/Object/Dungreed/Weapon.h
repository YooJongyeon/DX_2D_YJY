#pragma once
class Weapon
{
public:

	Weapon();
	~Weapon();

	void Update();
	void Render();

	void SetPlayer(shared_ptr<Transform> parent)
	{
		_quad->GetTransform()->SetParent(parent);
	}

private:
	shared_ptr<Quad> _quad;

};

