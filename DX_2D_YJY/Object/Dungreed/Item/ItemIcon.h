#pragma once
class ItemIcon
{
public:
	struct InstanceData
	{
		XMMATRIX matrix;
		Vector2 curFrame;
		Vector2 maxFrame;
	};

	struct IconData
	{
		~IconData() { data = nullptr; }
		bool isActive;
		string name;
		InstanceData* data;
		shared_ptr<Transform> transform;
	};

	ItemIcon();
	~ItemIcon();

	void Render();
	void SetIcon(string name, Vector2 pos);

	shared_ptr<Transform> GetTransform() { return _itemAtlas->GetTransform(); }

private:
	void SetItemIconTable();

	shared_ptr<Quad> _itemAtlas;
	unordered_map<string, vector<IconData>> _iconTable;

	vector<InstanceData> _instancingDataes;

	shared_ptr<VertexBuffer> _instanceBuffer;

	UINT _poolCount = 50;

};

