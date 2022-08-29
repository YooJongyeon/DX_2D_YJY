#include "framework.h"
#include "TestScene.h"

TestScene::TestScene()
{
	_angle = make_shared <Quad>(L"Resource/purpleaiming.png");
	_angle->GetTransform()->GetScale() *= 0.2f;
	_townMap = make_shared<TownMap>();
	_tileMap = make_shared<TileMap>();
	_creature = make_shared <Creature>();
	_test = make_shared<TestPlayer>();


	_test->SetTile(_tileMap->GetTile());
	_test->SetCreature(_creature);

	_creature->SetPlayer(_test);
	
	_FollowTrans = make_shared<Transform>();
	_FollowTrans->GetPos() = _test->GetPlayer()->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_FollowTrans);




	/*OUND->Add("BGM_1", "Resource/Sound/DungeonClose.wav");
	SOUND->Add("Slash01", "Resource/Sound/generalAttack.wav");
	SOUND->Play("BGM_1",0.5f);*/
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
	_creature->Update();
	_angle->Update();
	_test->Update();

	float distance = _test->GetTransform()->GetPos().Distance(_FollowTrans->GetPos());
	if (distance >= 30.0f)
	{
		_FollowTrans->GetPos() = LERP(_FollowTrans->GetPos(), _test->GetTransform()->GetPos(), 0.001f);
	}
	
	_angle->GetTransform()->GetPos() = MOUSE_POS;

	_test->AttackMonsters(_creature);
	_creature->AttackPlayer(_test);



	if (_creature->_hp <= 0)
	{
		_creature->_isActive = false;
	}
	

	/*if (KEY_Down(VK_F2))
	{
		SOUND->Play("Slash01", 0.5f);
	}*/
}

void TestScene::Render()
{
	
	_townMap->Render();
	_tileMap->Render();
	_creature->Render();
	_angle->Render();
	_test->Render();



}

void TestScene::PostRender()
{


}

void TestScene::NextScene()
{
	SCENE->SetScene("Dungreed");
}
