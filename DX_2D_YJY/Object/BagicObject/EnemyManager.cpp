#include "framework.h"
#include "EnemyManager.h"

EnemyManager* EnemyManager::_instance = nullptr;

EnemyManager::EnemyManager()
{
}

EnemyManager::~EnemyManager()
{
}

void EnemyManager::Add(wstring enemyFile, Vector2 maxFrame, float speed, UINT poolCount)
{
	size_t t = enemyFile.find(L"Creature/", 0);
	string temp = WstringToString(enemyFile.substr(t + 9, enemyFile.length()));
	temp = temp.substr(0, temp.size() - 4);

	if (_enemyMap.count(temp) > 0)
		return;

	vector<shared_ptr<Enemy>> v;
	v.reserve(poolCount);

	for (int i = 0; i < poolCount; i++)
	{
		shared_ptr<Enemy> effect = make_shared<Enemy>(enemyFile, maxFrame, speed);
		v.emplace_back(effect);
	}

	_enemyMap[temp] = v;
}

void EnemyManager::Play(string enemy, Vector2 pos)
{
	if (_enemyMap.count(enemy) == 0)
		return;

	for (auto& effect : _enemyMap[enemy])
	{
		if (effect->_isActive == false)
		{
			effect->Play(pos);
			return;
		}
	}
}

void EnemyManager::Update()
{
	for (auto& effects : _enemyMap)
	{
		for (auto& effect : effects.second)
		{
			effect->Update();
		}
	}
}

void EnemyManager::Render()
{
	for (auto& effects : _enemyMap)
	{
		for (auto& effect : effects.second)
		{
			effect->Render();
		}
	}
}

