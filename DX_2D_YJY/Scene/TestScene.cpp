#include "framework.h"
#include "TestScene.h"

TestScene::TestScene()
{
	_townMap = make_shared<TownMap>();
	_character = make_shared<Character>();

	_FollowTrans = make_shared<Transform>();
	_FollowTrans->GetPos() = _character->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_FollowTrans);
	Vector2 leftBottom = { 0,0 };
	Vector2 rightTop = { _townMap->GetTrasform()->GetHalfSize().x * 2.0f , _townMap -> GetTrasform()->GetHalfSize().y * 2.0f };
	Camera::GetInstance()->SetLeftBottom(leftBottom);
	Camera::GetInstance()->SetRightTop(rightTop);
}

TestScene::~TestScene()
{
}

void TestScene::Update()
{
	_townMap->Update();
	_character->Update();
	float distance = _character->GetTransform()->GetPos().Distance(_FollowTrans->GetPos());
	if (distance >= 30.0f)
	{
		_FollowTrans->GetPos() = LERP(_FollowTrans->GetPos(), _character->GetTransform()->GetPos(), 0.001f);
	}
}

void TestScene::Render()
{
	_townMap->Render();
	_character->Render();
}

void TestScene::PostRender()
{
	
}
