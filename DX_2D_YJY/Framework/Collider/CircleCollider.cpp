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

	_vertexShader = make_shared<VertexShader>(L"Shaders/ColliderShader/ColliderVertexShaer.hlsl");
	_pixelShader = make_shared<PixelShader>(L"Shaders/ColliderShader/ColliderPixelShader.hlsl");
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(VertexPos), _vertices.size());

	_colorBuffer = make_shared<ColorBuffer>();
	_colorBuffer->SetColor(GREAN);

	_transform = make_shared<Transform>();
	_parent = nullptr;
}

void CircleCollider::Update()
{
	_center = GetLocalPosition();
	_transform->UpdateWorldBuffer();
	_colorBuffer->Update();
}

void CircleCollider::Render()
{
	_transform->SetWorldBuffer(0);
	_colorBuffer->SetPSBuffer(0);

	_vertexBuffer->IASet(0);
	DEVICE_CONTEXT->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINESTRIP);

	_vertexShader->Set();
	_pixelShader->PSSet();
	DEVICE_CONTEXT->Draw(_vertices.size(), 0);
}

bool CircleCollider::IsCollision(const Vector2& pos)
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

bool CircleCollider::isCollision(shared_ptr<RectCollider> other, bool obb)
{
	return other->IsCollision(make_shared<CircleCollider>(*this), obb);
}
