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
void CircleCollider::CreateData()
{
	VertexPos vertex;
	for (int i = 0; i < 37; i++)
	{
		float x = cos(PI * (static_cast<float>(i) / 18)) * _radius;
		float y = sin(PI * (static_cast<float>(i) / 18)) * _radius;
		vertex.pos = XMFLOAT3(x, y, 0.0f);
		_vertices.push_back(vertex);
	}
	Collider::CreateData();
}

bool CircleCollider::IsCollision(const Vector2 pos)
{
	if (GetRadius() >= _center.Distance(pos))
		return true;

	return false;
}
bool CircleCollider::IsCollision(shared_ptr<CircleCollider> circle)
{
	float distance = (_center - circle->_center).Length();
	float distance2 = GetRadius() + circle->GetRadius();

	return distance2 > distance;
}

bool CircleCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	return rect->IsCollision(make_shared<CircleCollider>(*this));
}



