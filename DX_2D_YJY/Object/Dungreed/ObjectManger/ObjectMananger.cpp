#include "framework.h"
#include "ObjectMananger.h"

ObjectMananger* ObjectMananger::_instance = nullptr;

ObjectMananger::ObjectMananger()
{
}

ObjectMananger::~ObjectMananger()
{
}

void ObjectMananger::Add(wstring bossFile, Vector2 maxFrame, float speed, UINT poolCount)
{
	size_t t = bossFile.find(L"Creature/",0);
	string temp = WstringToString(bossFile.substr(t + 8, bossFile.length()));
	temp = temp.substr(0, temp.size() - 4);

	if (_objectMap.count(temp) > 0)
		return;

	vector<shared_ptr<Object>> o;
	o.reserve(poolCount);

	for (int i = 0; i < poolCount; i++)
	{
		shared_ptr<Object> object = make_shared<Object>(bossFile, maxFrame, speed);
		o.emplace_back(object);
	}

	_objectMap[temp] = o;
}

void ObjectMananger::Play(string boss, Vector2 pos)
{
	if (_objectMap.count(boss) == 0)
		return;

	for (auto& object : _objectMap[boss])
	{
		if (object->_isActive == false)
		{
			object->Play(pos);
			return;
		}
	}
}

void ObjectMananger::Update()
{
	for (auto& objects : _objectMap)
	{
		for (auto& object : objects.second)
		{
			object->Update();
		}
	}
}

void ObjectMananger::Render()
{
	for (auto& objects : _objectMap)
	{
		for (auto& object : objects.second)
		{
			object->Render();
		}
	}
}

