#include "framework.h"
#include "Texture.h"

Texture::Texture(wstring file)
{
    _vertexShader = make_shared<VertexShader>(L"Shaders/TextureVertexShader.hlsl");
    _pixelShader = make_shared<PixelShader>(L"Shaders/TexturePixelShader.hlsl");

    _srv = make_shared<SRV>(file);
  

    CreateVertices();
    UINT stride = sizeof(VertexUV);
    UINT count = _vertices.size();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, count);
    _indexBuffer = make_shared<IndexBuffer>(_indicies.data(), _indicies.size());

   
  
    _viewBuffer = make_shared<MatrixBuffer>();

    _transform = make_shared<Transform>();
}

Texture::~Texture()
{
}

void Texture::CreateVertices()
{
 
    {
        
        VertexUV v;
        v.pos = XMFLOAT3(-50, 50, 0.0f);
        v.uv = { 0.0f, 0.0f };
        _vertices.push_back(v);

        
        v.pos = XMFLOAT3(50, 50, 0.0f);
        v.uv = { 1.0f, 0.0f };
        _vertices.push_back(v);

        v.pos = XMFLOAT3(50, -50, 0.0f);
        v.uv = { 1.0f, 1.0f };
        _vertices.push_back(v);

        
        v.pos = XMFLOAT3(-50, -50, 0.0f);
        v.uv = { 0.0f, 1.0f };
        _vertices.push_back(v);
    }

    _indicies.push_back(0);
    _indicies.push_back(1);
    _indicies.push_back(2);

    _indicies.push_back(0);
    _indicies.push_back(2);
    _indicies.push_back(3);
}

void Texture::Update()
{
   
    _cameraPos = { -100.0f,0 };
    XMMATRIX cameraMatrix = XMMatrixRotationZ(_angle);
    cameraMatrix = XMMatrixTranslation(_cameraPos.x, _cameraPos.y, 0);
    _viewBuffer->SetMatrix(cameraMatrix);

    _viewBuffer->Update();
   
    _transform->UpdateWorldBuffer();
}

void Texture::Render()
{
    _transform->SetWorldBuffer(0);
    _viewBuffer->SetPSBuffer(1);
    _vertexBuffer->IASet(0);
    _indexBuffer->IASet();

    DEVICE_CONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    _srv->PSSet(0);
   
    _vertexShader->Set();
    _pixelShader->PSSet();

    DEVICE_CONTEXT->DrawIndexed(_indicies.size(), 0, 0);
}