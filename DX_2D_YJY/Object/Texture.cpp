#include "framework.h"
#include "Texture.h"

Texture::Texture(wstring file)
{
    _vertexShader = make_shared<VertexShader>(L"Shaders/TextureVertexShader.hlsl");
    _pixelShader = make_shared<PixelShader>(L"Shaders/TexturePixelShader.hlsl");

    _srv = make_shared<SRV>(file);
    _sampler = make_shared<SamplerState>();

    CreateVertices();
    UINT stride = sizeof(VertexUV);
    UINT count = _vertices.size();
    _vertexBuffer = make_shared<VertexBuffer>(_vertices.data(), stride, count);
    _indexBuffer = make_shared<IndexBuffer>(_indicies.data(), _indicies.size());

    _worldBuffer = make_shared<MatrixBuffer>();
    _viewBuffer = make_shared<MatrixBuffer>();
}

Texture::~Texture()
{
}

void Texture::CreateVertices()
{
 
    {
        
        VertexUV v;
        v.pos = XMFLOAT3(-200, 200, 0.0f);
        v.uv = { 0.0f, 0.0f };
        _vertices.push_back(v);

        
        v.pos = XMFLOAT3(200, 200, 0.0f);
        v.uv = { 1.0f, 0.0f };
        _vertices.push_back(v);

        v.pos = XMFLOAT3(200, -200, 0.0f);
        v.uv = { 1.0f, 1.0f };
        _vertices.push_back(v);

        
        v.pos = XMFLOAT3(-200, -200, 0.0f);
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
    XMMATRIX s = XMMatrixScaling(_scale.x, _scale.y, 1);
    XMMATRIX r = XMMatrixRotationZ(_angle);
    XMMATRIX t = XMMatrixTranslation(_pos.x, _pos.y, 0);
    _srt_matrix = s * r * t;
    _worldBuffer->SetMatrix(_srt_matrix);

    _cameraPos = { -100.0f,0 };
    XMMATRIX cameraMatrix = XMMatrixRotationZ(_angle);
    cameraMatrix = XMMatrixTranslation(_cameraPos.x, _cameraPos.y, 0);
    _viewBuffer->SetMatrix(cameraMatrix);

    _viewBuffer->Update();
    _worldBuffer->Update();
}

void Texture::Render()
{
    _worldBuffer->SetVSBuffer(0);
    _viewBuffer->SetPSBuffer(1);
    _vertexBuffer->IASet(0);
    _indexBuffer->IASet();

    DEVICE_CONTEXT->IASetPrimitiveTopology(D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST);
    _srv->PSSet(0);
    _sampler->PSSet(0);

    _vertexShader->Set();
    _pixelShader->PSSet();

    DEVICE_CONTEXT->DrawIndexed(_indicies.size(), 0, 0);
}