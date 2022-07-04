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

	 float Left()
	 { 
		 Vector2 temp = GetWorldPosition();
		 return temp.x - GetWorldHalfX();
	 }
	 float Right() 
	 {
		 Vector2 temp = GetWorldPosition();
		 return temp.x + GetWorldHalfX();
	 }
	 float Top() 
	 { 
		 Vector2 temp = GetWorldPosition();
		 return temp.y + GetWorldHalfY();
	 }
	 float Bottom() 
	 { 
		 Vector2 temp = GetWorldPosition();
		 return temp.y - GetWorldHalfY();
	 }

	 float GetWorldHalfX() { return _halfSize.x * GetWorldScale().x; }
	 float GetWorldHalfY() { return _halfSize.y * GetWorldScale().y; }

	 ObbDesc GetObb();

	 bool AABB(shared_ptr<RectCollider> rect);
	 bool OBB(shared_ptr<RectCollider> rect);

	 bool AABB(shared_ptr<class CircleCollider> circle);
	 bool OBB(shared_ptr<class CircleCollider> circle);

	 virtual bool IsCollision(const Vector2& pos) override;
	 virtual bool IsCollision(shared_ptr<RectCollider> rect, bool isobb = false) override;
	 virtual bool IsCollision(shared_ptr<CircleCollider> circle , bool isobb = false) override;
	 
	 float SeoareatAxis(Vector2 separate, Vector2 e1, Vector2 e2);

private:
	Vector2 _halfSize = { 0,0 };


};

