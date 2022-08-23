#include "framework.h"
#include "VertexBuffer.h"

VertexBuffer::VertexBuffer(void* data, UINT stride, UINT count, UINT offset)
    : _stride(stride)
    , _count(count)
    , _offset(offset)
    , _data(data)
{
    CreateVertexBuffer(data);
}

VertexBuffer::~VertexBuffer()
{
}
void VertexBuffer::Update()
{
    DEVICE_CONTEXT->Map(_vertexBuffer.Get(), 0, D3D11_MAP_WRITE_DISCARD, 0, &_subResource);
    memcpy(_subResource.pData, _data, _stride * _count);
    DEVICE_CONTEXT->Unmap(_vertexBuffer.Get(), 0);
}

void VertexBuffer::CreateVertexBuffer(void* data)
{
    // Vertex ����: Vertex
    D3D11_BUFFER_DESC bd = {};
    bd.Usage = D3D11_USAGE_DYNAMIC;
    bd.ByteWidth = _stride * _count;
    bd.BindFlags = D3D11_BIND_VERTEX_BUFFER;
    bd.CPUAccessFlags = D3D11_CPU_ACCESS_WRITE;

    D3D11_SUBRESOURCE_DATA initData = {};
    initData.pSysMem = data;
    initData.SysMemPitch = 0;
    initData.SysMemSlicePitch = 0;

    // ���� �������� ��� ���� ����
    DEVICE->CreateBuffer(&bd, &initData, _vertexBuffer.GetAddressOf());
}

void VertexBuffer::IASet(int slot)
{
    DEVICE_CONTEXT->IASetVertexBuffers(slot, 1, _vertexBuffer.GetAddressOf(), &_stride, &_offset);
    Update();
}

