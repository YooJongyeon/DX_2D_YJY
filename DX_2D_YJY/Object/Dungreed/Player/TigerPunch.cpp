#include "framework.h"
#include "TigerPunch.h"

TigerPunch::TigerPunch()
{
    _Weapon = make_shared<Weapon>(L"Resource/Weapon/TigerPunch.png", Vector2(10, 1), 0.1f);
}

TigerPunch::~TigerPunch()
{
}

void TigerPunch::Update()
{
	if (_isActive == false)
		return;

	_Weapon->Update();
}

void TigerPunch::Render()
{
	if (_isActive == false)
		return;
	_Weapon->Render();
}

void TigerPunch::GetPlay(Vector2 pos)
{
	_Weapon->Play();
}

void TigerPunch::SetDirection(Vector2 dir)
{
	_direction = dir;
	_Weapon->GetTransform()->GetAngle() = dir.Angle();
}

bool TigerPunch::IsCollision(shared_ptr<Enemy> Enemy)
{
	if (Enemy->_isActive == false && _isActive == false)
		return false;
	if (_collider->IsCollision(Enemy->GetColl()))
	{
		return true;
	}
	return false;
}
