#pragma once

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

class ColerBuffer : public ConstantBuffer
{
public:

	struct Data
	{
		XMFLOAT4 color;
	};
	
	ColerBuffer()
		:ConstantBuffer(&_data, sizeof(Data) )
	{
		_data.color = { 1,1,1,1 };
	}

private:
	Data _data;



};