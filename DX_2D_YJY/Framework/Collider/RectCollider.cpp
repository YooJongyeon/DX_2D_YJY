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

void RectCollider::CreateData()
{
	VertexPos vertex;
	//좌측상단
	vertex.pos = XMFLOAT3(-_halfSize._x, _halfSize._y, 0.0f);
	_vertices.push_back(vertex);
	// 우측상단
	vertex.pos = XMFLOAT3(+_halfSize._x, _halfSize._y, 0.0f);
	_vertices.push_back(vertex);
	//우측 하단
	vertex.pos = XMFLOAT3(+_halfSize._x, -_halfSize._y, 0.0f);
	_vertices.push_back(vertex);
	//좌측 하단
	vertex.pos = XMFLOAT3(-_halfSize._x, -_halfSize._y, 0.0f);
	_vertices.push_back(vertex);
	//좌측 상단
	vertex.pos = XMFLOAT3(-_halfSize._x, _halfSize._y, 0.0f);
	_vertices.push_back(vertex);


	_vertexShader = make_shared<VertexShader>(L"Shaders/ColliderShader/ColliderVertexShaer.hlsl");
	_pixelShader = make_shared<PixelShader>(L"Shaders/ColliderShader/ColliderPixelShader.hlsl");
	_vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), sizeof(VertexPos), _vertices.size());

	_colorBuffer = make_shared<ColorBuffer>();
	_colorBuffer->SetColor(GREEN);
	
	_transform = make_shared<Transform>();
	_parent = nullptr;
}

void RectCollider::Update()
{
	if (_isActive == false)
		return;

	if (_isCollision == true)
		_colorBuffer->SetColor(RED);
	else 
		_colorBuffer->SetColor(GREEN);
	
	_center = GetPosition();

	_transform->UpdateWorldBuffer();
	_colorBuffer->Update();
}

void RectCollider::Render()
{
	if (_isActive == false)
		return;
	_transform->SetWorldBuffer(0);
	_colorBuffer->SetPSBuffer(0);

	_vertexBuffer->IASet(0);
	DEVICE_CONTEXT->IASetPrimitiveTopology(D3D_PRIMITIVE_TOPOLOGY_LINESTRIP);

	_vertexShader->Set();
	_pixelShader->PSSet();
	DEVICE_CONTEXT->Draw(_vertices.size(), 0);
}

bool RectCollider::IsCollision(shared_ptr<RectCollider> rect)
{
	if (rect->Left() < this->Right() && rect->Right() > this->Left() &&
		rect->Bottom() < this->Top() && rect->Top() > this->Bottom())
	{
		return  _isCollision =true;
	}

	return  _isCollision = false;
}

bool RectCollider::IsCollision(Vector2 pos)
{
	if (pos._x < Left() || pos._x > Right())
		return  _isCollision = false;

	if (pos._y > Top() || pos._y < Bottom())
		return  _isCollision = false;

	return _isCollision = true;
}
