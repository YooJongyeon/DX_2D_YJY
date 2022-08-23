#include "framework.h"
#include "Quad.h"

Quad::Quad(wstring file, wstring vs, wstring ps)
{
    _vertexShader = ADD_VS(vs);
    _pixelShader = ADD_PS(ps);

    _texture = Texture::Add(file);
    _halfSize = _texture->Getsize() * 0.5f;

    CreateData();

    UINT stride = sizeof(VertexUV);
    UINT count = _vertices.size();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, count);
    _indexBuffer = make_shared<IndexBuffer>(_indicies.data(), _indicies.size());

    _transform = make_shared<Transform>();
}

Quad::Quad(wstring file, Vector2 Size, wstring vs, wstring ps)
{
    _vertexShader = ADD_VS(vs);
    _pixelShader = ADD_PS(ps);

    _texture = Texture::Add(file);
    _halfSize = Size;

    CreateData();

    UINT stride = sizeof(VertexUV);
    UINT count = _vertices.size();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, count);
    _indexBuffer = make_shared<IndexBuffer>(_indicies.data(), _indicies.size());

    _transform = make_shared<Transform>();
}

Quad::~Quad()
{
}

void Quad::Update()
{
    if (_isActive == false)
        return;
    _transform->UpdateWorldBuffer();
}

void Quad::Render()
{
    if (_isActive == false)
        return;
    _transform->SetMatrixBuffer(0);

    _vertexBuffer->IASet(0);
    _indexBuffer->IASet();

    IASetPT();

    // Texture 
    _texture->Set(0);
    SMAPLER_STATE->PSSet(0);

    _vertexShader->Set();
    _pixelShader->Set();

    DEVICE_CONTEXT->DrawIndexed(_indicies.size(), 0, 0);
}

void Quad::SetRender()
{
    _vertexBuffer->IASet(0);
    _indexBuffer->IASet();

    IASetPT();

   
    _texture->Set(0);
    SMAPLER_STATE->PSSet(0);

    _vertexShader->Set();
    _pixelShader->Set();
}

void Quad::CreateData()
{
    {
        _vertices.emplace_back(-_halfSize.x, _halfSize.y, 0, 0); // ������
        _vertices.emplace_back(_halfSize.x, _halfSize.y, 1, 0); // ������ ��
        _vertices.emplace_back(-_halfSize.x, -_halfSize.y, 0, 1); // ���� �Ʒ�
        _vertices.emplace_back(_halfSize.x, -_halfSize.y, 1, 1); // ������ �Ʒ�
    }

    _indicies.push_back(0);
    _indicies.push_back(1);
    _indicies.push_back(2);

    _indicies.push_back(2);
    _indicies.push_back(1);
    _indicies.push_back(3);
}

const Vector2& Quad::GetHalfSize()
{
   
    Vector2 temp;
    temp.x = _halfSize.x * _transform->GetScale().x;
    temp.y = _halfSize.y * _transform->GetScale().y;

    return temp;

}

Vector2 Quad::LeftBottom()
{
    return _transform->GetPos() - GetHalfSize();
}

Vector2 Quad::RightTop()
{
    return _transform->GetPos() + GetHalfSize();
}
