#include "framework.h"
#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
}

void Collider::Update()
{
	_center = GetLocalPosition();
	_transform->UpdateWorldBuffer();
	_colorBuffer->Update();
}

void Collider::Render()
{
	_transform->SetWorldBuffer(0);
	_colorBuffer->SetPSBuffer(0);

	_vertexBuffer->IASet(0);
	DEVICE_CONTEXT->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINESTRIP);

	_vertexShader->Set();
	_pixelShader->PSSet();
	DEVICE_CONTEXT->Draw(_vertices.size(), 0);
}

void Collider::CreateData()
{
	_vertexShader = make_shared<VertexShader>(L"Shaders/ColliderShader/ColliderVertexShaer.hlsl");
	_pixelShader = make_shared<PixelShader>(L"Shaders/ColliderShader/ColliderPixelShader.hlsl");
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(VertexPos), _vertices.size());

	_colorBuffer = make_shared<ColorBuffer>();
	_colorBuffer->SetColor(GREAN);

	_transform = make_shared<Transform>();
	_parent = nullptr;
}

bool Collider::IsCollision(shared_ptr<Collider> col)
{
	switch (col->_type)
	{
	case ColType::CIRCLE :
	{
		if (this->IsCollision(dynamic_pointer_cast<CircleCollider>(col)))
			return true;
		break;
	}

	case ColType::RECT:
	{
		if (this->IsCollision(dynamic_pointer_cast<RectCollider>(col)))
			return true;
		break;
	}

	default:
		break;
	}

	return false;
}
