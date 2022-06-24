#pragma once
class CircleCollider
{
public:
	CircleCollider(float radius ,const Vector2& center);
	~CircleCollider();

	void CreateData();
	void Update();
	void Render();

	const Vector2& GetWorldPosition() { return _transform->GetWorldPos(); }
	Vector2& GetPosition() { return _transform->GetPos(); }
	float& GetAngle() { return _transform->GetAnagle(); }


private:
	Vector2 _center;
	float _radius = 0.0f;


	//Math
	vector<VertexPos> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;

	//Collider 초록색으로 보통 세팅이 되어있다
	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<Transform> _parent;
	shared_ptr<Transform> _transform;

};

