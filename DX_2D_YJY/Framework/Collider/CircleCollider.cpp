#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius)
	:_radius(radius)
{
	CreateData();
}

CircleCollider::~CircleCollider()
{
}

void CircleCollider::Update()
{
	Collider::Update();
}
void CircleCollider::Render()
{
	Collider::Render();
}
void CircleCollider::CreateData()
{
	_type = Collider::ColType::CIRCLE;

	VertexPos vertex;
	for (int i = 0; i < 37; i++)
	{
		float theta = PI * 2 / 36;
		vertex.pos.x = _radius * cosf(theta * i);
		vertex.pos.y = _radius * sinf(theta * i);
		vertex.pos.z = 0;

		_vertices.push_back(vertex);
	}
	Collider::CreateData();
}

bool CircleCollider::IsCollision(const Vector2& pos)
{
	float distance = _transform->GetWorldPos().Distance(pos);
	float radius = GetRadius();
	if (distance < radius)
		return true;

	return false;
}
bool CircleCollider::IsCollision(shared_ptr<CircleCollider> circle, bool isobb )
{
	Vector2 t = circle->GetWorldPosition();
	Vector2 t2 = this->GetWorldPosition();
	Vector2 t3 = t2 - t;
	float distance = (t3).Length();
	if (distance < GetRadius() + circle->GetRadius())
		return true;

	return false;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect , bool isobb )
{
	return rect->IsCollision(make_shared<CircleCollider>(*this), isobb);
}



