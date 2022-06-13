#pragma once
class ConstantBuffer
{
public:
	ConstantBuffer(void* data, UINT count);
	~ConstantBuffer();

	void Update();

	void SetVSBuffer(UINT slot);
	void SetPSBuffer(UINT slot);

private:
	Microsoft::WRL::ComPtr<ID3D11Buffer> _buffer;

	void* _data;
	UINT _count;
};

