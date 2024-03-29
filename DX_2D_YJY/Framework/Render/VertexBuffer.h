#pragma once
class VertexBuffer
{
public:
	VertexBuffer(void* data, UINT stride, UINT count, UINT offset = 0);
	~VertexBuffer();

	void IASet(int slot);
	
private:
	void Update();
	void CreateVertexBuffer(void* data);

	Microsoft::WRL::ComPtr<ID3D11Buffer> _vertexBuffer;
	D3D11_MAPPED_SUBRESOURCE _subResource;

	void* _data;
	UINT _stride;
	UINT _count;
	UINT _offset;
};

