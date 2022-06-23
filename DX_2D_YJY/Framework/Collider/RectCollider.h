#pragma once
class RectCollider 
{
private:
	struct ObbDesc 
	{
		Vector2 _position;
		Vector2 _direction[2];

		float _lenght[2];
	};

public:
	RectCollider(const Vector2& halfSize = { 1.0f,1.0f });
	~RectCollider();

	 void CreateData();
	 void Update();
	 void Render();

	 float Left() { return _center._x - _halfSize._x; }
	 float Right() { return _center._x + _halfSize._x; }
	 float Top() { return _center._y + _halfSize._y; }
	 float Bottom() { return _center._y - _halfSize._y; }


	 ObbDesc GetObb();

	 bool AABB(shared_ptr<RectCollider> rect);
	 bool OBB(shared_ptr<RectCollider> rect);

	 bool IsCollision(shared_ptr<RectCollider> rect , bool obb = false);
	 bool IsCollision(const Vector2& pos);

	 float SeoareatAxis(Vector2 separate, Vector2 e1, Vector2 e2);


	 const Vector2& GetWorldPosition() { return _transform->GetWorldPos(); }
	 Vector2& GetPosition() { return _transform->GetPos(); }
	 float& GetAngle() { return _transform->GetAnagle(); }

	 bool _isDebug;
	 bool _isCollision = false;

private:
	Vector2 _halfSize = { 0,0 };
	Vector2 _center;

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

