#pragma once
class RectCollider : public Collider
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

	 virtual void Update() override;
	 virtual void CreateData() override;

	 float Left() { return _center._x - _halfSize._x; }
	 float Right() { return _center._x + _halfSize._x; }
	 float Top() { return _center._y + _halfSize._y; }
	 float Bottom() { return _center._y - _halfSize._y; }


	 ObbDesc GetObb();

	 bool AABB(shared_ptr<RectCollider> rect);
	 bool OBB(shared_ptr<RectCollider> rect);

	 bool AABB(shared_ptr<class CircleCollider> circle);
	 bool OBB(shared_ptr<class CircleCollider> circle);

	 virtual bool IsCollision(const Vector2 pos) override;
	 virtual bool IsCollision(shared_ptr<RectCollider> rect) override;
	 virtual bool IsCollision(shared_ptr<CircleCollider> circle) override;
	 
	 float SeoareatAxis(Vector2 separate, Vector2 e1, Vector2 e2);

private:
	Vector2 _halfSize = { 0,0 };
	Vector2 _center;

};

