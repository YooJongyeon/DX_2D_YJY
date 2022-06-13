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