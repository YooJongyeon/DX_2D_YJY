#include "framework.h"
#include "Weapon.h"

Weapon::Weapon()
{
	_quad = make_shared <Quad>(L"Resource/Weapon/ShortSword.png");
	_quad->GetTransform()->GetScale() = { 0.25f, 0.25f };
}

Weapon::~Weapon()
{
}

void Weapon::Update()
{
	_quad->Update();
}

void Weapon::Render()
{
	_quad->Render();
}
