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

}

void Collider::Render()
{
	_transform->SetWorldBuffer(0);
	_colorBuffer->SetPSBuffer(0);

	_vertexBuffer->IASet(0);
	IASetPT(D3D_PRIMITIVE_TOPOLOGY_LINESTRIP);

	_vertexShader->Set();
	_pixelShader->Set();
	DEVICE_CONTEXT->Draw(_vertices.size(), 0);
}

void Collider::CreateData()
{
	_vertexShader = ADD_VS(L"Shaders/ColliderShader/ColliderVertexShader.hlsl");
	_pixelShader = ADD_PS(L"Shaders/ColliderShader/ColliderPixelShader.hlsl");
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(VertexPos), _vertices.size());

	_colorBuffer = make_shared<ColorBuffer>();
	_colorBuffer->SetColor(GREEN);

	_transform = make_shared<Transform>();
	
}

bool Collider::IsCollision(shared_ptr<Collider> col , bool isobb)
{
	switch (col->_type)
	{
	case ColType::CIRCLE :
	{
		return this->IsCollision(dynamic_pointer_cast<CircleCollider>(col), isobb);
		break;
	}

	case ColType::RECT:
	{
		return this->IsCollision(dynamic_pointer_cast<RectCollider>(col), isobb);
		break;
	}

	default:
		break;
	}

	return false;
}
