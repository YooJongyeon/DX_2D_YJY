#include "framework.h"
#include "Sprite.h"

Sprite::Sprite(wstring file, Vector2 maxFrame)
    :_maxFrame(maxFrame)
{
    _vertexShader = ADD_VS(L"Shaders/TextureVertexShader.hlsl");
    _pixelShader = ADD_PS(L"Shaders/ActionShader.hlsl");

    _texture = Texture::Add(file);
    _halfSize = _texture->Getsize() * 0.5f;
  
    _transform = make_shared<Transform>();

    _frameBuffer = make_shared<FrameBuffer>();
    _frameBuffer->data.maxFrame.x = _maxFrame.x;
    _frameBuffer->data.maxFrame.y = _maxFrame.y;

    _actionBuffer = make_shared<ActionBuffer>();
    _actionBuffer->data.maxSize = _texture->Getsize();

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
    if (_isActive == false)
        return;
    Quad::Update();
}

void Sprite::Render()
{
    if (_isActive == false)
        return;
    _frameBuffer->SetPSBuffer(0);
    _actionBuffer->SetPSBuffer(0);
    Quad::Render();
}

void Sprite::CreateData()
{
    Vector2 halfSize = _texture->Getsize() * 0.5f;
    halfSize.x /= _frameBuffer->data.maxFrame.x;
    halfSize.y /= _frameBuffer->data.maxFrame.y;

    {
        _vertices.emplace_back(-halfSize.x, halfSize.y, 0, 0); // ������
        _vertices.emplace_back(halfSize.x, halfSize.y, 1, 0); // ������ ��
        _vertices.emplace_back(-halfSize.x, -halfSize.y, 0, 1); // ���� �Ʒ�
        _vertices.emplace_back(halfSize.x, -halfSize.y, 1, 1); // ������ �Ʒ�
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
    v.x = _halfSize.x / _maxFrame.x;
    v.y = _halfSize.y / _maxFrame.y;


	return v;
}

void Sprite::SetClipToActionBuffer(Action::Clip clip)
{
    _actionBuffer->data.size = clip._size;
    _actionBuffer->data.startPos = clip._startPos;
}


void Sprite::SetClip(Action::Clip clip)
{
   // clip
   // - startPos {0, 520}
   // - size     {w, h}
   // clips.emplace_back(0		, y, w, h, Texture::Add(L"Resource/zelda.png"));


   // frameBuffer
   // - maxFrame
   // - curFrame.x : 0 ~ maxFrame.x
   // - curFrame.y : 0 ~ maxFrame.y
   //                                0 , w, w * 2 , w * 3
   //                                0   1   2    ,   3
    _frameBuffer->data.curFrame.x = clip._startPos.x / clip._size.x;
    _frameBuffer->data.curFrame.y = clip._startPos.y / clip._size.y;
}


