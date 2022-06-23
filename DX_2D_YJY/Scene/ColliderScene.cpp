#include "framework.h"
#include "ColliderScene.h"

ColliderScene::ColliderScene()
{
	_rectCollider1 = make_shared<RectCollider>(Vector2(100, 50));
	_rectCollider2 = make_shared<RectCollider>(Vector2(50, 100));

	_rectCollider2->GetPosition() = Vector2(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f);
}

ColliderScene::~ColliderScene()
{
}

void ColliderScene::Update()
{
	_rectCollider1->IsCollision(MOUSE_POS);
	_rectCollider2->IsCollision(_rectCollider1,true);

	_rectCollider1->Update();
	_rectCollider2->Update();

}

void ColliderScene::Render()
{
	
	_rectCollider1->Render();
	_rectCollider2->Render();
	
	
}

void ColliderScene::PostRender()
{
	ImGui::SliderFloat("Rect1 PosX", &_rectCollider1->GetPosition()._x, 0, WIN_WIDTH);
	ImGui::SliderFloat("Rect1 PosY", &_rectCollider1->GetPosition()._y, 0, WIN_HEIGHT);

	ImGui::SliderFloat("Rect1 Angle", &_rectCollider1->GetAngle(),0, 2 *PI);
}
