#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared <Player>();
	_angle = make_shared <Texture>(L"Resource/purpleaiming.png");

	_monster.reserve(_monsterCount);
	for (int i = 0; i < _monsterCount; i++)
	{
		shared_ptr<Monster> temp = make_shared<Monster>();
		temp->GetTrasform()->GetPos()._x += _pos;
		_pos = (i + 1) * 200;
		_monster.push_back(temp);
	}
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	_player->Update();
	_angle->Update();
	for (auto& monster : _monster)
	{
		monster->Update();
		if (monster->_hp <= 0)
			monster->_isActive = false;
	}

	_player->AttackMonsters(_monster);

	_angle->GetTransform()->GetPos() = MOUSE_POS;
}

void DungreedScene::Render()
{
	_player->Render();
	_angle->Render();
	for (auto& monster : _monster)
	{
		monster->Render();

	}
}



