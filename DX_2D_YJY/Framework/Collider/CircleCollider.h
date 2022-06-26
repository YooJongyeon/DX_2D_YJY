#pragma once
class CircleCollider : public Collider
{
public:
	CircleCollider(float radius );
	~CircleCollider();

	virtual void Update() override;
	virtual void CreateData() override;

	virtual bool IsCollision(const Vector2 pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle) override;

	float GetRadius(){ return _radius * _transform ->GetScale()._x; }


private:
	Vector2 _center;
	float _radius ;
};

