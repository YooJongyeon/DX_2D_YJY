#pragma once
class Store
{
public:
	Store(Vector2 size);
	~Store();

private:
	shared_ptr< class ItemIcon> _itemIcon;

	shared_ptr<Quad> _backGround;
	shared_ptr<BGorSlotBuffer> _bsBuffer;
	vector<shared_ptr<Quad>> _slots;

	vector<ItemData> _items;

	Vector2 _size = { 0,0 };
	Vector2 _slotOffset = { 75.0f,90.0f };

	int _slotSize = 9;
};

