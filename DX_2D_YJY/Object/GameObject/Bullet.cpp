#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_texture = make_shared<Texture>(L"Resource/redbullet.png");

	_collider = make_shared<CircleCollider>(20);
	_collider->SetParent(_texture->GetTransform());
	_collider->GetLocalPosition()._x += 20;


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
	_collider->Update();
	
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_texture->Render();
	_collider->Render();
}

void Bullet::SetDirection(Vector2 dir)
{
	_direction = dir;
	_texture->GetTransform()->GetAnagle() = dir.Angle();
}

bool Bullet::IsCollision(shared_ptr<class Monster> monster)
{
	if (monster->_isActive == false && _isActive == false)
			return false;
	if (_collider->IsCollision(monster->GetCollider()))
	{
		return true;
	}
	return false;
}




