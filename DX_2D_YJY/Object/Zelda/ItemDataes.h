#pragma once

struct ItemData
{
	string name;
	int value = 0;
	int prive = 0;
	int type = 0;
	int attack = 0;
	int defence = 0;

};

class ItemDataes
{
public:
	ItemDataes();
	~ItemDataes();

	void InitData();


private:
	vector<ItemData> _items;

};

