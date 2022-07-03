#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring file, Vector2 maxFrame)
    :_maxFrame(maxFrame)
{
    _vertexShader = ADD_VS(L"Shaders/TextureVertexShader.hlsl");
    _pixelShader = ADD_PS(L"Shaders/SpriteShader.hlsl");

    _texture = Texture::Add(file);
    _maxFrame = _texture->Getsize() * 0.5f;

    _transform = make_shared<Transform>();

    _frameBuffer = make_shared<FrameBuffer>();
    _frameBuffer->data.maxFrame.x = _maxFrame._x;
    _frameBuffer->data.maxFrame.y = _maxFrame._x;

    CreateData();

    UINT stride = sizeof(VertexUV);
    UINT count = _vertices.size();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, count);
    _indexBuffer = make_shared<IndexBuffer>(_indicies.data(), _indicies.size());
}

Sprite::~Sprite()
{
}

void Sprite::Update()
{
    Quad::Update();
}

void Sprite::Render()
{
    Quad::Render();
}

void Sprite::CreateData()
{
    Vector2 haifSize = _texture->Getsize() * 0.5f;
    haifSize._x /= _frameBuffer->data.maxFrame.x;
    haifSize._y /= _frameBuffer->data.maxFrame.y;

    {
        _vertices.emplace_back(-_halfSize._x, _halfSize._y, 0, 0);
        _vertices.emplace_back(_halfSize._x, _halfSize._y, 1, 0);
        _vertices.emplace_back(-_halfSize._x, -_halfSize._y, 0, 1);
        _vertices.emplace_back(_halfSize._x, -_halfSize._y, 1, 1);
    }

    _indicies.push_back(0);
    _indicies.push_back(1);
    _indicies.push_back(2);

    _indicies.push_back(2);
    _indicies.push_back(1);
    _indicies.push_back(3);
}

Vector2 Sprite::GetHalfFrameSize()
{
    Vector2 v;
    v._x = _halfSize._x / _maxFrame._x;
    v._y = _halfSize._y / _maxFrame._y;


	return Vector2();
}


