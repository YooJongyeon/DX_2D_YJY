#pragma once
class ItemDataes
{
public:
	ItemDataes();
	~ItemDataes();


	ItemData* FindItem(string name);

	void InitData();
	const unordered_map<string, ItemData>& GetItemTable() { return _items; }

private:
	unordered_map<string, ItemData> _items;

};

