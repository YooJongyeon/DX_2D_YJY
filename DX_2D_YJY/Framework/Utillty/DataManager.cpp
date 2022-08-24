#include "framework.h"
#include "DataManager.h"

DataManager* DataManager::_instance = nullptr;
void DataManager::AddMoney(int amount)
{
}

void DataManager::SubMoney(int amount)
{
}

DataManager::DataManager()
{
	_itemDataes = make_shared<ItemDataes>();
}

DataManager::~DataManager()
{
}
