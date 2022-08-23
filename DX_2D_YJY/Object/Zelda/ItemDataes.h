#pragma once
class ItemDataes
{
public:
	ItemDataes();
	~ItemDataes();


	ItemData* FindItem(string name);
	void InitData();


private:
	unordered_map<string, ItemData> _items;

};

