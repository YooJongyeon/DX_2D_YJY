#include "framework.h"
#include "CircleCollider.h"

CircleCollider::CircleCollider(float radius, const Vector2& center)
	:_radius(radius)
	, _center(center)
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
	_colorBuffer->SetColor(GREEN);

	_transform = make_shared<Transform>();
	_parent = nullptr;
}

void CircleCollider::Update()
{
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
