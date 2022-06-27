#include "framework.h"
#include "Monster.h"

Monster::Monster()
{
	_texture = make_shared <Texture>(L"Resource/monster.png");
	_texture->GetTransform()->GetScale() = { 1.5f, 1.5f };
	_texture->GetTransform()->GetPos() = Vector2(WIN_WIDTH * 0.7f, WIN_HEIGHT * 0.7f);

	_collider = make_shared<RectCollider>(Vector2{ 55,55 });
	_collider->SetParent(_texture->GetTransform());
}

Monster::~Monster()
{
}

void Monster::Update()
{
	_texture->Update();
	_collider->Update();
}

void Monster::Render()
{
	ImGui::Text("Target hp: %d", (UINT)_hp);
	_texture->Render();
	_collider->Render();
}

