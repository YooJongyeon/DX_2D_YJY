#pragma once
class Collider
{
public:
	Collider();
	virtual ~Collider();

	virtual void Update();
	virtual void Render();

	virtual void CreateData();

	void SetParent(shared_ptr<Transform> parent) { _parent = parent; }


private:
	Vector2 _center;

	vector<VertexPos> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;
	shared_ptr<ColerBuffer> _colorBuffer;

	shared_ptr<Transform> _parent;
};

