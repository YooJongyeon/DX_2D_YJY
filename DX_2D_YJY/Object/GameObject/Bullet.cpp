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

	
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_texture->Render();
}

void Bullet::SetDirection(Vector2 dir)
{

	Vector2 temp = _texture->GetTransform()->GetWorldPos();
	temp._x += cos(_texture->GetTransform()->GetAnagle()) * 100 ;
	temp._y += sin(_texture->GetTransform()->GetAnagle()) ;
	_texture->GetTransform()->SetPos(temp);

	_direction = dir;
}



