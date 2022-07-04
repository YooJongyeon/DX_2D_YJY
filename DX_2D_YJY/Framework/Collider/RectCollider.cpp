#include "framework.h"
#include "RectCollider.h"

RectCollider::RectCollider(const Vector2& halfSize)
	:_halfSize(halfSize)
{
	CreateData();
}

RectCollider::~RectCollider()
{
}

void RectCollider::Update()
{

	Collider::Update();
}

void RectCollider::CreateData()
{
	_type = Collider::ColType::RECT;
	VertexPos vertex;
	//좌측상단
	vertex.pos = XMFLOAT3(-_halfSize.x, _halfSize.y, 0.0f);
	_vertices.push_back(vertex);
	// 우측상단
	vertex.pos = XMFLOAT3(+_halfSize.x, _halfSize.y, 0.0f);
	_vertices.push_back(vertex);
	//우측 하단
	vertex.pos = XMFLOAT3(+_halfSize.x, -_halfSize.y, 0.0f);
	_vertices.push_back(vertex);
	//좌측 하단
	vertex.pos = XMFLOAT3(-_halfSize.x, -_halfSize.y, 0.0f);
	_vertices.push_back(vertex);
	//좌측 상단
	vertex.pos = XMFLOAT3(-_halfSize.x, _halfSize.y, 0.0f);
	_vertices.push_back(vertex);

	Collider::CreateData();
	
}

float RectCollider::SeoareatAxis(Vector2 separate, Vector2 e1, Vector2 e2)
{
	float r1 = abs(separate.Dot(e1));
	float r2 = abs(separate.Dot(e2));

	return r1 + r2;
}

RectCollider::ObbDesc RectCollider::GetObb()
{
	ObbDesc obbDesc;

	obbDesc._position = GetWorldPosition();
	obbDesc._lenght[0] = GetWorldHalfX();
	obbDesc._lenght[1] = GetWorldHalfY();

	XMFLOAT4X4 world;
	XMStoreFloat4x4(&world, _transform->GetMatrix());
	obbDesc._direction[0] = { world._11, world._12 };
	obbDesc._direction[1] = { world._21, world._22 };
	obbDesc._direction[0].Normallize();
	obbDesc._direction[1].Normallize();

	return obbDesc;
}

bool RectCollider::AABB(shared_ptr<RectCollider> rect)
{
	if (rect->Left() < this->Right() && rect->Right() > this->Left() &&
		rect->Bottom() < this->Top() && rect->Top() > this->Bottom())
	{
		return true;
	}

	return false;
}

bool RectCollider::OBB(shared_ptr<RectCollider> rect)
{
	ObbDesc obbA = GetObb();
	ObbDesc obbB = rect->GetObb();

	//A의 가로세로의 단위백터 , 백터
	Vector2 nea1 = obbA._direction[0];
	Vector2 ea1 = nea1 * obbA._lenght[0];
	Vector2 nea2 = obbA._direction[1];
	Vector2 ea2 = nea2 * obbA._lenght[1];

	//B의 가로세로의 단위백터 , 백터
	Vector2 neb1 = obbB._direction[0];
	Vector2 eb1 = neb1 * obbB._lenght[0];
	Vector2 neb2 = obbB._direction[1];
	Vector2 eb2 = neb2 * obbB._lenght[1];

	// A의 중점과 B의 중점 사이의 거리
	Vector2 distance = obbA._position - obbB._position;

	float lengthA = ea1.Length();
	float lengthB = SeoareatAxis(nea1, eb1, eb2);
	float length = abs(distance.Dot(nea1));// 두 점 사이의 거리 직교화
	if (length > lengthA + lengthB)
	{
		return false;
	}
		
	lengthA = ea2.Length();
	lengthB = SeoareatAxis(nea2, eb1, eb2);
	length = abs(distance.Dot(nea2));// 두 점 사이의 거리 직교화
	if (length > lengthA + lengthB)
	{
		return false;
	}

	// B 가로 세로 길이
	lengthA = SeoareatAxis(neb1, ea1, ea2);
	lengthB = eb1.Length();
	length = abs(distance.Dot(neb1));// 두 점 사이의 거리 직교화
	if (length > lengthA + lengthB)
	{
		return false;
	}

	lengthA = SeoareatAxis(neb2, ea1, ea2);
	lengthB = eb2.Length();
	length = abs(distance.Dot(neb2));// 두 점 사이의 거리 직교화
	if (length > lengthA + lengthB)
	{
		return false;
	}

	return true;
}


bool RectCollider::AABB(shared_ptr<CircleCollider> circle)
{
	
	if (IsCollision(circle->GetWorldPosition()))
		return true;

	if ((circle->GetWorldPosition().x > Left() && circle->GetWorldPosition().x < Right())
		|| (circle->GetWorldPosition().y < Top() && circle->GetWorldPosition().y > Bottom()))
	{
		if (circle->GetWorldPosition().x < Left() - circle->GetRadius() || circle->GetWorldPosition().x > Right() + circle->GetRadius())
			return false;
		if (circle->GetWorldPosition().y > Top() + circle->GetRadius() || circle->GetWorldPosition().y < Bottom() - circle->GetRadius())
			return false;

		return true;
	}

	if (circle->IsCollision(Vector2(Right(), Top())))
		return true;
	if (circle->IsCollision(Vector2(Left(), Top())))
		return true;
	if (circle->IsCollision(Vector2(Right(), Bottom())))
		return true;
	if (circle->IsCollision(Vector2(Left(), Bottom())))
		return true;

	return false;
}

bool RectCollider::OBB(shared_ptr<CircleCollider> circle)
{
	ObbDesc obbA = GetObb();

	Vector2 nea1 = obbA._direction[0];
	Vector2 ea1 = nea1 * obbA._lenght[0];
	Vector2 nea2 = obbA._direction[1];
	Vector2 ea2 = nea2 * obbA._lenght[1];

	Vector2 circleV = circle->GetWorldPosition();
	Vector2 distanceV = circleV - obbA._position;

	//원이 대각에 위치할 때
	float diagona = sqrtf(obbA._lenght[0] + obbA._lenght[0] + obbA._lenght[1] + obbA._lenght[1]);
	if (distanceV.Length() > circle->GetRadius() + diagona)
	{
		return false;
	}

	float lengthA = ea1.Length();
	float lengthB = circle->GetRadius();
	float lengthDistance = abs(distanceV.Dot(nea1));

	if (lengthDistance > lengthA + lengthB)
		return false;


	lengthA = ea2.Length();
	lengthB = circle->GetRadius();
	lengthDistance = abs(distanceV.Dot(nea2));

	if (lengthDistance > lengthA + lengthB)
		return false;

	return true;
}

bool RectCollider::IsCollision(const Vector2& pos)
{
	if (pos.x < Left() || pos.x > Right())
		return false;
	if (pos.y > Top() || pos.y < Bottom())
		return false;
	return true;
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> rect, bool isobb)
{
	if (isobb)
	{
		return OBB(rect);
	}
	else
	{
		return AABB(rect);
	}

}

bool RectCollider::IsCollision(shared_ptr<CircleCollider> circle , bool isobb)
{
	if (isobb)
	{
		return OBB(circle);
	}
	else
	{
		return AABB(circle);
	}
}






