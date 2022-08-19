#include "framework.h"
#include "TestScene.h"

TestScene::TestScene()
{
	_townMap = make_shared<TownMap>();
	_tileMap = make_shared<TileMap>();
	_character = make_shared<Character>();
	_creature = make_shared <Creature>();

	_button = make_shared<Bulton>();
	_button->SetScale(Vector2(0.1f, 0.1f));
	_button->SetText("Next");
	_button->SetPosition({ 100,WIN_HEIGHT - 100 });
	_button->SetEvent(std::bind(&TestScene::NextScene, this));
	

	_character->SetTile(_tileMap->GetTile());

	_FollowTrans = make_shared<Transform>();
	_FollowTrans->GetPos() = _character->GetTransform()->GetPos();
	
	Camera::GetInstance()->SetTarget(_FollowTrans);
	Vector2 leftBottom = {0,0};
	Vector2 rightTop = { _townMap->GetTrasform()->GetHalfSize().x *2.0f,_townMap->GetTrasform()->GetHalfSize().y * 2.0f };
	Camera::GetInstance()->SetLeftBottom(leftBottom);
	Camera::GetInstance()->SetRightTop(rightTop);
	
	

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
	_character->Update();
	_creature->Update();

	


	float distance = _character->GetTransform()->GetPos().Distance(_FollowTrans->GetPos());
	if (distance >= 30.0f)
	{
		_FollowTrans->GetPos() = LERP(_FollowTrans->GetPos(), _character->GetTransform()->GetPos(), 0.001f);
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
	_character->Render();
	_creature->Render();

}

void TestScene::PostRender()
{
	if (_timeStop == true)
	{
		_button->Update();
		_button->PostRender();
	}
	

}

void TestScene::NextScene()
{
	SCENE->SetScene("Dungreed");
}
