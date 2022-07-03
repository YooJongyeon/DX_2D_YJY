#pragma once
class Revolver
{
public:

	Revolver();
	~Revolver();

	void Update();
	void Render();

	void SetPlayer(shared_ptr<Transform> parent)
	{
		_quad->GetTransform()->SetParent(parent);
	}


private:

	shared_ptr<Quad> _quad;

};

