#pragma once
class ItemDataes;
class DataManager
{
public:
	static void Create()
	{
		if (_instance == nullptr)
		{
			_instance = new DataManager();
		}
	}

	static void Delete()
	{
		if (_instance != nullptr)
		{
			delete _instance;
		}
	}

	static DataManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
	}

	void AddMoney(int amount);
	void SubMoney(int amount);
	shared_ptr<ItemDataes> GetItemDataes() { return _itemDataes; }

private:
	DataManager();
	~DataManager();

	static DataManager* _instance;

	int _moneny = 0;
	shared_ptr<ItemDataes> _itemDataes;
};

