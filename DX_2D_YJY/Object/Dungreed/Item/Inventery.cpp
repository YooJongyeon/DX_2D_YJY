#include "framework.h"
#include "Inventery.h"

Inventery::Inventery(Vector2 size)
	:_size(size)
{
	_rtv = make_shared<RenderTarget>(_size.x, _size.y);
	_backGround = make_shared<Quad>(L"Inventory", _size);
	shared_ptr<Texture> texture = Texture::Add(L"InventoryTexture", _rtv->GetSRV());
	_backGround->SetTexture(texture);
	_backGround->GetTransform()->GetPos() = { CENTER.x + 100.0f, CENTER.y };
	_backGround->GetTransform()->GetPos() = { CENTER.x + 300.0f, CENTER.y };
	_backGround->Update();

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
			_slots[x + y * 3]->GetTransform()->GetPos().x = _backGround->LeftBottom().x + _slotOffset.x + _slotOffset.x * x;
			_slots[x + y * 3]->GetTransform()->GetPos().y = _backGround->RightTop().y - _slotOffset.y - _slotOffset.y * y;
		}
	}

	_bsBuffer = make_shared<BGorSlotBuffer>();

	_itemIcon = make_shared<ItemIcon>();
	_items.resize(_slotSize);
}

Inventery::~Inventery()
{
}

void Inventery::Update()
{
	for (auto& slot : _slots)
		slot->Update();
}

void Inventery::Render()
{
	_backGround->Render();

	_bsBuffer->data.bgOrSlet = 1;
	_bsBuffer->SetPSBuffer(0);
	for (auto& slot : _slots)
		slot->Render();

	_itemIcon->Render();



}

void Inventery::SetRTV()
{
	_rtv->Set();
}

void Inventery::PostRender()
{
}

void Inventery::AddItme(ItemData data)
{
	int slotNum = 0;
	bool isFull = false;
	for (auto data : _items)
	{
		if (data.name == "NOME")
		{
			isFull = false;
			break;
		}

		isFull = true;
		slotNum++;
		
	}

	if (isFull)
	{
		return;
	}
	
	_items.push_back(data);
	string name = data.name;
	name = name.substr(name.find('_'));

	Vector2 pos = _slots[slotNum]->GetTransform()->GetPos();

	_itemIcon->SetIcon(name, pos);
}

void Inventery::SubItem(string name)
{
}


