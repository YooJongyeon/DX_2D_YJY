#pragma once
class CircleCollider : public Collider
{
public:
	CircleCollider(float radius );
	~CircleCollider();

	virtual void Update() override;
	virtual void CreateData() override;

	virtual bool IsCollision(const Vector2& pos) override;
	virtual bool IsCollision(shared_ptr<RectCollider> rect , bool isobb = false) override;
	virtual bool IsCollision(shared_ptr<CircleCollider> circle , bool isobb = false) override;

	float GetRadius(){ return _radius * _transform ->GetWorldScale().x; }


private:
	float _radius ;
};

