#pragma once
class RectCollider 
{
public:
	RectCollider(const Vector2& halfSize = { 1.0f,1.0f });
	 ~RectCollider();

	 void CreateData() ;


	 void Update();
	 void Render();

	 //Rect Rect
	 //Rect Point

	 Vector2& GetPosition() { return _transform->GetPos(); }

	 bool IsCollision(shared_ptr<RectCollider> rect);
	 bool IsCollision(Vector2 pos);

	 bool _isActive;
	 bool _isCollision = false;
	 float Left() { return _center._x - _halfSize._x; }
	 float Right() { return _center._x + _halfSize._x; }
	 float Top() { return _center._y + _halfSize._y; }
	 float Bottom() { return _center._y - _halfSize._y; }

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

