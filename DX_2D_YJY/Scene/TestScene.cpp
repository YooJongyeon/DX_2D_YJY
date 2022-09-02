#include "framework.h"
#include "TestScene.h"

TestScene::TestScene()
{
	_angle = make_shared <Quad>(L"Resource/ShootingCursor2.png");
	_angle->GetTransform()->GetScale() * 0.2f;
	_townMap = make_shared<TownMap>();
	_tileMap = make_shared<TileMap>();

	_test = make_shared<TestPlayer>();
	_test->SetTile(_tileMap->GetTile());

	_creature.reserve(_monsterCount);
	for (int i = 0; i < _monsterCount; i++)
	{
		shared_ptr<Creature> temp = make_shared<Creature>();
		temp->SetPostion(_pos, _pos);
		temp->SetPlayer(_test);
		_pos = (i + 1) * 200;
		_creature.push_back(temp);
	}

	_FollowTrans = make_shared<Transform>();
	_FollowTrans->GetPos() = _test->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_FollowTrans);
	Vector2 leftBottom = { 0,0 };
	Vector2 rightTop = { _test->GetPlayer()->GetSprite()->GetHalfSize().x *40.0f,  _test->GetPlayer()->GetSprite()->GetHalfSize().y * 40.0f };
	Camera::GetInstance()->SetLeftBottom(leftBottom);
	Camera::GetInstance()->SetRightTop(rightTop);


}

TestScene::~TestScene()
{
}

void TestScene::Update()
{
	if (KEY_Down(VK_ESCAPE))
		_timeStop = !_timeStop;

	if (_timeStop == true)
		return;

	_townMap->Update();
	_tileMap->Update();
	_test->Update();
	_angle->Update();

	for (auto& monster : _creature)
	{
		monster->Update();

		monster->AttackPlayer(_test);
		_test->AttackMonsters(monster);

		if (monster->_hp <= 0)
			monster->_isActive = false;
	}

	float distance = _test->GetTransform()->GetPos().Distance(_FollowTrans->GetPos());
	if (distance >= 30.0f)
	{
		_FollowTrans->GetPos() = LERP(_FollowTrans->GetPos(), _test->GetTransform()->GetPos(), 0.001f);
	}
	_angle->GetTransform()->GetPos() = MOUSE_WORLDPOS;
	
}

void TestScene::Render()
{

	_townMap->Render();
	_tileMap->Render();
	for (auto& monster : _creature)
	{
		monster->Render();

	}
	_test->Render();
	_angle->Render();

}

void TestScene::PostRender()
{


}

void TestScene::NextScene()
{
	SCENE->SetScene("Dungreed");
}
