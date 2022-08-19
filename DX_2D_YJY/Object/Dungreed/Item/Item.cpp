#include "framework.h"
#include "Item.h"

Item::Item(ItemType Type, string name, float price, float addHp, float attack, float defence)
	:_type(Type)
	,_price(price)
	,_addHp(addHp)
	,_attack(attack)
	,_defence(defence)
	,_name(name)
{
}

Item::~Item()
{
}
