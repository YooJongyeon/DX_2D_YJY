#include "framework.h"
#include "DataManager.h"

DataManager* DataManager::_instance = nullptr;
DataManager::DataManager()
{
	_itemDataes = make_shared<ItemDataes>();
}

DataManager::~DataManager()
{
}
void DataManager::AddMoney(int amount)
{
	_moneny += amount;
}

void DataManager::SubMoney(int amount)
{
}

