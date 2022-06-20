#pragma once
class Revolver
{
public:

	Revolver();
	~Revolver();

	void Update();
	void Render();

	void SetPlayer(Transform* transform)
	{
		_texture->GetTransform()->SetParent(transform->GetMatrix());
	}


private:

	shared_ptr<Texture> _texture;

};

