#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	_quad = make_shared <Quad>(L"Resource/monster.png");
	_quad->GetTransform()->GetScale() = {0.5f, 0.5f };
	_quad->GetTransform()->GetPos() = Vector2(WIN_WIDTH * 0.3f, WIN_HEIGHT * 0.7f);

	_collider = make_shared<RectCollider>(_quad->GetHalfSize());
	_collider->SetParent(_quad->GetTransform());

	_isActive = true;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	if (_isActive == false)
		return;
	_quad->Update();
	_collider->Update();	
}

void Monster::Render()
{

	if (_isActive == false)
		return;
	ImGui::Text("Target hp: %d", (UINT)_hp);
	_quad->Render();
	_collider->Render();

}

