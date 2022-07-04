#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared <Player>();
	_angle = make_shared <Quad>(L"Resource/purpleaiming.png");
	_angle->GetTransform()->GetScale() *= 0.2f;

	_zelda = make_shared<Sprite>(L"Resource/zelda.png", Vector2(10, 8));
	_zelda->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.5f;


	_monster.reserve(_monsterCount);
	for (int i = 0; i < _monsterCount; i++)
	{
		shared_ptr<Monster> temp = make_shared<Monster>();
		temp->GetTrasform()->GetPos().x += _pos;
		_pos = (i + 1) * 200;
		_monster.push_back(temp);
	}

	//action
	vector<Action::Clip> clips;
	clips.emplace_back(0,1040 / 2,1200 / 10,1040 / 8,Texture::Add(L"Resource/zelda.png"));

	_action = make_shared<Action>(clips);
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	_player->Update();
	_angle->Update();
	_zelda->Update();
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
	_zelda->Render();
	_angle->Render();
	for (auto& monster : _monster)
	{
		monster->Render();

	}
}

void DungreedScene::PostRender()
{
	

}



