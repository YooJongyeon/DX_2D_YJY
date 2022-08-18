#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_player = make_shared <Player>();
	_angle = make_shared <Quad>(L"Resource/purpleaiming.png");
	_angle->GetTransform()->GetScale() *= 0.2f;

	_monster.reserve(_monsterCount);
	for (int i = 0; i < _monsterCount; i++)
	{
		shared_ptr<Monster> temp = make_shared<Monster>();
		temp->GetTrasform()->GetPos().x += _pos;
		_pos = (i + 1) * 200;
		_monster.push_back(temp);
	}


	_button = make_shared<Bulton>();
	_button->SetScale(Vector2(0.1f, 0.1f));
	_button->SetText("Next");
	_button->SetPosition({ 100, WIN_HEIGHT - 100 });
	_button->SetEvent(std::bind(&DungreedScene::PrevScene, this));
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Inif()
{
	_player->Inif();
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

void DungreedScene::PostRender()
{
	

}


void DungreedScene::PrevScene()
{
	SCENE->SetScene("Test");
}

