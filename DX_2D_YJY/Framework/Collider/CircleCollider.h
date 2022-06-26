#pragma once
class CircleCollider
{
public:
	CircleCollider(float radius );
	~CircleCollider();

	void CreateData();
	void Update();
	void Render();

	bool IsCollision(shared_ptr<CircleCollider> circle);
	bool IsCollision(const Vector2& pos) ;
	bool isCollision(shared_ptr<class RectCollider> other, bool obb = false);

	const Vector2& GetWorldPosition() { return _transform->GetWorldPos(); }
	Vector2& GetLocalPosition() { return _transform->GetPos(); }
	float& GetAngle() { return _transform->GetAnagle(); }

	void SetRed() { _colorBuffer->SetColor(RED);}
	void SetGrean() { _colorBuffer->SetColor(GREAN);}

	bool _isCollision = false;

	float GetRadius(){ return _radius * _transform ->GetScale()._x; }


private:
	Vector2 _center;
	float _radius ;

	vector<VertexPos> _vertices;
	shared_ptr<VertexBuffer> _vertexBuffer;

	shared_ptr<VertexShader> _vertexShader;
	shared_ptr<PixelShader> _pixelShader;

	shared_ptr<ColorBuffer> _colorBuffer;

	shared_ptr<Transform> _parent;
	shared_ptr<Transform> _transform;

};

