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
		: ConstantBuffer(&_data, sizeof(Data))
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
	} data;

	FrameBuffer()
		: ConstantBuffer(&data, sizeof(Data))
	{
		data.maxFrame = { 1.0f,1.0f };
		data.curFrame = { 0.0f,0.0f };
	}
};

class ActionBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 size;
		XMFLOAT2 startPos;
		XMFLOAT2 maxSize;
		XMFLOAT2 padding; // 16바이트의 정수배 만큼 넘겨줘야한다.
	} data;

	ActionBuffer()
		: ConstantBuffer(&data, sizeof(Data))
	{
		data.size = { 1.0f,1.0f };
		data.startPos = { 0.0f,0.0f };
		data.maxSize = { 1.0f,1.0f };
	}
};

class FilterBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int selected = 0;
		int value1 = 0;
		int value2 = 0;
		int value3 = 0;
	}data;

	FilterBuffer()
		: ConstantBuffer(&data, sizeof(Data))
	{

	}
};

class ImageSizeBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		XMFLOAT2 size = { 0.0f,0.0f };
		XMFLOAT2 padding = { 0.0f,0.0f };
	}data;

	ImageSizeBuffer()
		: ConstantBuffer(&data, sizeof(Data))
	{

	}
};

class ButtonBuffer : public ConstantBuffer
{
public:
	struct Data
	{
		int state = 0;
		float hovered = 0.0f;
		float clicked = 0.0f;
		float padding;
	} data;

	ButtonBuffer()
		: ConstantBuffer(&data, sizeof(Data))
	{

	}
};

class BGorSlotBuffer :public ConstantBuffer
{
public:
	struct Data
	{
		int bgOrSlet = 0;
		float padding0 = 0.0f;
		float padding1 = 0.0f;
		float padding2 = 0.0f;
	} data;

	BGorSlotBuffer()
		: ConstantBuffer(&data, sizeof(Data))
	{

	}

};