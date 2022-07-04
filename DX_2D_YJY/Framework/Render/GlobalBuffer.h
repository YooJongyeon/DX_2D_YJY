#pragma once

inline void IASetPT(D3D_PRIMITIVE_TOPOLOGY type = D3D_PRIMITIVE_TOPOLOGY_TRIANGLELIST)
{
	DEVICE_CONTEXT->IASetPrimitiveTopology(type);
}

class MatrixBuffer : public ConstantBuffer
{
	struct Data
	{
		XMMATRIX _matrix;
	};
public:
	MatrixBuffer()
		: ConstantBuffer(&_data, sizeof(Data))
	{
		_data._matrix = XMMatrixIdentity();
	}

	void SetMatrix(XMMATRIX matrix)
	{
		_data._matrix = XMMatrixTranspose(matrix);
	}

private:
	Data _data;
};

class ColorBuffer : public ConstantBuffer
{
public:

	struct Data
	{
		XMFLOAT4 color;
	};
	
	ColorBuffer()
		:ConstantBuffer(&_data, sizeof(Data) )
	{
		_data.color = { 1,1,1,1 };
	}

	void SetColor(const XMFLOAT4& color) { _data.color = color; }


private:
	Data _data;



};

class FrameBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 maxFrame;
		XMFLOAT2 curFrame;
	}data;

	FrameBuffer()
		:ConstantBuffer(&data,sizeof(Data))
	{
		data.maxFrame = { 1.0f,1.0f };
		data.curFrame = { 0.0f,0.0f };
	}

};