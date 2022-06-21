#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_texture = make_shared<Texture>(L"Resource/redbullet.png");

}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false)
		return;

	_texture->GetTransform()->GetPos() += _direction * 300.0f * DELTA_TIME;
	_texture->Update();

	_runTime += DELTA_TIME;
	if (_runTime > _destroyTime)
	{
		_isActive = false;
		_runTime = 0.0f;
	}
	
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_texture->Render();
}

void Bullet::SetDirection(Vector2 dir)
{
	_direction = dir;
	_texture->GetTransform()->GetAnagle() = dir.Angle();
}



