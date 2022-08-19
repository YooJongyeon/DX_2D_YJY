#pragma once
class ItemIcon
{
public:
	struct InstancingDataes
	{
		XMMATRIX matrix;
		Vector2 curFrame;
		Vector2 maxFrame;
	};

	ItemIcon(wstring file, Vector2 maxFrame);
	~ItemIcon();


private:
	shared_ptr<Quad> _quad;

	vector<InstancingDataes> _instancingDataes;
	shared_ptr<VertexBuffer> _instancingBuffer;

	UINT _poolCount = 55;

};

