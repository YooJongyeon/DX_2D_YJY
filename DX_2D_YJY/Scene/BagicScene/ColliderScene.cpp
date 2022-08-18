#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_circleCollider2 = make_shared<CircleCollider>(80);
	_circleCollider1 = make_shared<CircleCollider>(50);
	_rectColldier1 = make_shared<RectCollider>(Vector2(50, 50));
	
	_circleCollider1->GetLocalPosition() = Vector2(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f);
	_rectColldier1->GetLocalPosition() = Vector2(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	
	if (_circleCollider1->IsCollision(_rectColldier1))
		_circleCollider1->SetRed();
	else
		_circleCollider1->SetGreen();

	//if (_circleCollider1->IsCollision(MOUSE_POS))
	//	_circleCollider1->SetRed();
	//else
	//	_circleCollider1->SetGreen();

	_circleCollider2->Update();
	_circleCollider1->Update();
	_rectColldier1->Update();

}

void ColliderScene::Render()
{
	_circleCollider2->Render();
	_circleCollider1->Render();
	_rectColldier1->Render();
}

void ColliderScene::PostRender()
{
	ImGui::SliderFloat("Rect1 PosX", &_rectColldier1->GetLocalPosition().x, 0, WIN_WIDTH);
	ImGui::SliderFloat("Rect1 PosY", &_rectColldier1->GetLocalPosition().y, 0, WIN_HEIGHT);

	ImGui::SliderFloat("Circle PosX", &_circleCollider1->GetLocalPosition().x, 0, WIN_WIDTH);
	ImGui::SliderFloat("Circle PosY", &_circleCollider1->GetLocalPosition().y, 0, WIN_HEIGHT);

	ImGui::SliderFloat("Rect1 Angle", &_rectColldier1->GetAngle(),0, 2 *PI);
}
