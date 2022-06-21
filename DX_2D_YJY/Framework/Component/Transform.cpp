#include "framework.h"
#include "Transform.h"

Transform::Transform()
{
	_worldBuffer = make_shared<MatrixBuffer>();
}

Transform::~Transform()
{
}

void Transform::UpdateWorldBuffer()
{
    XMMATRIX s = XMMatrixScaling(_scale._x, _scale._y, 1);
    XMMATRIX r = XMMatrixRotationZ(_angle);
    XMMATRIX t = XMMatrixTranslation(_pos._x, _pos._y, 0);
    _srt_matrix = s * r * t;

    if (_parent != nullptr)
    {
        _srt_matrix *= _parent->GetMatrix();
        _worldBuffer->SetMatrix(_srt_matrix);
    }
    _worldBuffer->SetMatrix(_srt_matrix);
    _worldBuffer->Update();
}

void Transform::SetWorldBuffer(int slot)
{
    _worldBuffer->SetVSBuffer(0);
}
