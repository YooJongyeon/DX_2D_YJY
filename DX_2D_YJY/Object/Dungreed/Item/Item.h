#pragma once
class Item
{
public:
	enum ItemType
	{
		NOME,
		POFLON,
		WEAPON,
		ARMOR
	};

	Item(ItemType Type, string name, float price,float addHp, float attack,float defence );
	~Item();



private:
	ItemType _type = NOME;

	string _name;
	float _price = 0.0f;
	float _addHp = 0.0f;
	float _attack = 0.0f;
	float _defence = 0.0f;
};

