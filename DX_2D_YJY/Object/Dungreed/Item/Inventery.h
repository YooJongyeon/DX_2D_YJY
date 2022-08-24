#pragma once
class Item;
class Inventery
{
public:
	Inventery(Vector2 size);
	~Inventery();

	void Update();
	void Render();
	void SetRTV();
	void PostRender();

	void AddItme(ItemData data);
	void SubItem(string name);


private:
	bool _isActive = false;

	shared_ptr<RenderTarget> _rtv;
	shared_ptr<Quad> _backGround;

	shared_ptr<ItemIcon> _itemIcon;
	vector<shared_ptr<Quad>> _slots;

	vector<ItemData> _items;
	shared_ptr<BGorSlotBuffer> _bsBuffer;
	
	Vector2 _size = {0,0};
	Vector2 _slotOffset = { 75.0f,90.0f };

	int _slotSize = 9;
	UINT _money = 30000;




};

