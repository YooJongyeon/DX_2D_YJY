#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_adventure = make_shared <Adventure>();
	_anagle = make_shared <Texture>(L"Resource/purpleaiming.png");
	_rectCollider = make_shared<RectCollider>(Vector2{ 100.0f,100.0f });
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	_adventure->Update();
	_anagle->Update();

	_rectCollider->Update();

	_anagle->GetTransform()->GetPos() = MOUSE_POS;
}

void DungreedScene::Render()
{

	_adventure->Render();
	_rectCollider->Render();
	_anagle->Render();

	//imgui
	ImGui::SliderFloat("ColliderPosX", &_rectCollider->GetPosition()._x, 0, 1280);
	ImGui::SliderFloat("ColliderPosX", &_rectCollider->GetPosition()._y, 0, 720);
}



