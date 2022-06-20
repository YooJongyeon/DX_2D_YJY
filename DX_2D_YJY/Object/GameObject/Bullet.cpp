#include "framework.h"
#include "Bullet.h"

Bullet::Bullet()
{
	_redBullet = make_shared<Texture>(L"Resource/redbullet.png");
	_redBullet->GetTransform()->m_pos = { 150.0f, 0 };
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (_isActive == false)
		return;
	
	_checkTime += DELTA_TIME;
	if (_checkTime > 1.0f)
	{
		_isActive = false;
		_checkTime = 0.0f;
	}
	
	double t = DELTA_TIME;
	float temp = t * 300.0f;
	_redBullet->GetTransform()->m_pos += _movePosition * temp;
	_redBullet->Update();
}

void Bullet::Render()
{
	if (_isActive == false)
		return;

	_redBullet->Render();
}


