#include "framework.h"
#include "Store.h"
#include "Object/Zelda/ItemDataes.h"

Store::Store(Vector2 size)
	: _size(size)
	, _slotSize(8)
{
	_backGround = make_shared<Quad>(L"Store", _size,
		L"Shaders/TextureVertexShader.hlsl",
		L"Shaders/SlotPixelShader.hlsl");

	_backGround->GetTransform()->GetPos() = { CENTER.x - 300.0f, CENTER.y };
	_backGround->Update();

	_itemIcon = make_shared<ItemIcon>();
	_items.reserve(_slotSize);

	for (int i = 0; i < _slotSize; i++)
	{
		shared_ptr<Quad> slot = make_shared<Quad>(L"InventorySlot", Vector2(50.0f, 50.0f),
			L"Shaders/TextureVertexShader.hlsl",
			L"Shaders/SlotPixelShader.hlsl");

		_slots.push_back(slot);
	}

	for (int y = 0; y < 3; y++)
	{
		for (int x = 0; x < 3; x++)
		{
			if (x + y * 3 >= _slotSize)
				break;

			_slots[x + y * 3]->GetTransform()->GetPos().x = _backGround->LeftBottom().x + _slotOffset.x + _slotOffset.x * x;
			_slots[x + y * 3]->GetTransform()->GetPos().y = _backGround->RightTop().y - _slotOffset.y - _slotOffset.y * y;
		}
	}

	InitStore();

	_bsBuffer = make_shared<BGorSlotBuffer>();
}

Store::~Store()
{
}

void Store::InitStore()
{
	auto map = DATA->GetItemDataes()->GetItemTable();

	for (auto pair : map)
	{
		_items.push_back(pair.second);
	}

	_slotSize = _items.size();

	for (int i = 0; i < _slotSize; i++)
	{
		string name = _items[i].name;
		name = name.substr(0, name.find('_'));
		_itemIcon->SetIcon(name, _slots[i]->GetTransform()->GetPos());
	}
}

void Store::Update()
{
	for (auto& slot : _slots)
		slot->Update();
}



void Store::PostRender()
{
	_bsBuffer->data.bgOrSlet = 0;
	_bsBuffer->SetPSBuffer(0);
	_backGround->Render();

	_bsBuffer->data.bgOrSlet = 1;
	_bsBuffer->SetPSBuffer(1);
	for (auto& slot : _slots)
		slot->Render();

	_itemIcon->Render();
}
