#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	_texture = make_shared <Texture>(L"Resource/monster.png");
	_texture->GetTransform()->GetScale() = { 1.5f, 1.5f };
	_texture->GetTransform()->GetPos() = Vector2(WIN_WIDTH * 0.3f, WIN_HEIGHT * 0.7f);

	_collider = make_shared<RectCollider>(Vector2{ 55,55 });
	_collider->SetParent(_texture->GetTransform());

	_isActive = true;
}

Monster::~Monster()
{
}

void Monster::Update()
{
	if (_isActive == false)
		return;
	_texture->Update();
	_collider->Update();	
}

void Monster::Render()
{

	if (_isActive == false)
		return;
	ImGui::Text("Target hp: %d", (UINT)_hp);
	_texture->Render();
	_collider->Render();

}

