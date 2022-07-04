#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_quad = make_shared<Quad>(L"Resource/redbullet.png");
	_quad->GetTransform()->GetScale() = { 0.1f, 0.1f };

	_collider = make_shared<CircleCollider>(_quad->GetHalfSize().x);
	_collider->SetParent(_quad->GetTransform());
	_collider->GetLocalPosition().x += 20;


}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false)
		return;

	_quad->GetTransform()->GetPos() += _direction * 300.0f * DELTA_TIME;
	_quad->Update();

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

	_quad->Render();
	_collider->Render();
}

void Bullet::SetDirection(Vector2 dir)
{
	_direction = dir;
	_quad->GetTransform()->GetAnagle() = dir.Angle();
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




