#include "framework.h"
#include "ProjectScene.h"

ProjectScene::ProjectScene()
{
	_angle = make_shared <Quad>(L"Resource/ShootingCursor2.png");
	_angle->GetTransform()->GetScale() = { 0.5f, 0.5f };


	_townMap = make_shared<TownMap>();
	_tileMap = make_shared<TileMap>();

	_player = make_shared<TestPlayer>();
	_player->SetTile(_tileMap->GetTile());

	_release.reserve(_releaseCount);
	for (int i = 0; i < _releaseCount; i++)
	{
		shared_ptr<Creature> temp = make_shared<Creature>();
		temp->SetPlayer(_player);
		_pos.x = (i + 1) * 350.0f;
		_pos.y = (i + 1) * 100.0f;
		temp->SetPostion(_pos, _pos);
		_release.push_back(temp);
	}

	_ghost.reserve(_GostCount);
	for (int i = 0; i < _GostCount; i++)
	{
		shared_ptr<Ghost> temp = make_shared<Ghost>();
		temp->SetPlayer(_player);
		_gostPos.x = (i + 1) * 250.0f;
		_gostPos.y = (i + 1) * 200.0f;
		temp->SetPostion(_gostPos, _gostPos);
		_ghost.push_back(temp);
	}

	_FollowTrans = make_shared<Transform>();
	_FollowTrans->GetPos() = _player->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_FollowTrans);
	Vector2 leftBottom = { 0,0 };
	Vector2 rightTop = { _townMap->GetTrasform()->GetHalfSize().x * 2.0f, _townMap->GetTrasform()->GetHalfSize().y * 2.0f };
	Camera::GetInstance()->SetLeftBottom(leftBottom);
	Camera::GetInstance()->SetRightTop(rightTop);

	SOUND->Add("JailField", "Resource/Sound/1.JailField.wav");
	SOUND->Play("JailField", 0.5f);
}

ProjectScene::~ProjectScene()
{
}

void ProjectScene::Update()
{
	if (KEY_Down(VK_ESCAPE))
		_timeStop = !_timeStop;

	if (_timeStop == true)
		return;


	_townMap->Update();
	_tileMap->Update();
	_player->Update();
	_angle->Update();

	for (auto& release : _release)
	{
		release->Update();

		release->AttackPlayer(_player);
		_player->AttackMonsters(release);

		if (release->_hp <= 0)
		{

			release->_isActive = false;
		}

	}

	for (auto& ghost : _ghost)
	{
		ghost->Update();

		ghost->AttackPlayer(_player);
		_player->AttackGhost(ghost);

		if (ghost->_hp <= 0)
		{
			ghost->_isActive = false;
		}

	}

	float distance = _player->GetTransform()->GetPos().Distance(_FollowTrans->GetPos());
	if (distance >= 30.0f)
	{
		_FollowTrans->GetPos() = LERP(_FollowTrans->GetPos(), _player->GetTransform()->GetPos(), 0.001f);
	}

	_angle->GetTransform()->GetPos() = MOUSE_WORLDPOS;
}

void ProjectScene::Render()
{
	_townMap->Render();
	_tileMap->Render();
	for (auto& release : _release)
	{
		release->Render();
	}

	for (auto& ghost : _ghost)
	{
		ghost->Render();

	}
	_player->Render();
	_angle->Render();
}

void ProjectScene::PostRender()
{
}
