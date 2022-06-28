#include "framework.h"
#include "Player.h"

Player::Player()
{
	_texture = make_shared <Texture>(L"Resource/adventure.png");
	_texture->GetTransform()->GetScale() = { 0.5f, 0.5f };


	_revolverTrans = make_shared<Transform>();
	_revolverTrans->SetParent(_texture->GetTransform());
	_revolverTrans->GetPos()._x = 50;

	_revolver = make_shared <Revolver>();
	_revolver->SetPlayer(_revolverTrans);


	_bullet.reserve(30);
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Bullet> temp = make_shared<Bullet>();
		temp->_isActive = false;
		_bullet.push_back(temp);
	}
	_collider = make_shared<RectCollider>(Vector2{ 90,90 });
	_collider->SetParent(_texture->GetTransform());
}

Player::~Player()
{
}

void Player::Update()
{
	Move();
	Aiming();
	Fire();

	_texture->Update();
	_revolver->Update();
	_revolverTrans->UpdateWorldBuffer();
	_collider->Update();

	for (auto& bullet : _bullet)
	{
		bullet->Update();
	}
}

void Player::Render()
{
	_texture->Render();
	_revolver->Render();
	_collider->Render();

	for (auto& bullet : _bullet)
	{
		bullet->Render();
	}
}

void Player::AttackMonsters(vector<shared_ptr<class Monster>> _monster)
{
	for (auto& bullet : _bullet)
	{
		if (bullet->_isActive == false)
		{
			continue;
		}
		for (auto& monster : _monster)
		{
			if (bullet->IsCollision(monster))
			{
				monster->GetCollider()->SetRed();
				monster->_hp -= 50;
				bullet->_isActive = false;
			}
			else
			{
				monster->GetCollider()->SetGreen();
			}
		}
	}
	
}


void Player::Move()
{
	if (KEY_PRESS('A'))
	{
		_texture->GetTransform()->GetPos()._x -= 100 * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_texture->GetTransform()->GetPos()._x += 100 * DELTA_TIME;
	}

	if (KEY_PRESS('W'))
	{
		_texture->GetTransform()->GetPos()._y += 100 * DELTA_TIME;
	}

	if (KEY_PRESS('S'))
	{
		_texture->GetTransform()->GetPos()._y -= 100 * DELTA_TIME;
	}

}

void Player::Aiming()
{
	Vector2 v = MOUSE_POS - _revolverTrans->GetWorldPos();
	float angle = v.Angle();
	_revolverTrans->GetAnagle() = angle;
}

void Player::Fire()
{
	if (KEY_Down(VK_LBUTTON))
	{
		for (auto& bullet : _bullet)
		{
			if (bullet->_isActive == false)
			{
				Vector2 v = MOUSE_POS - _revolverTrans->GetWorldPos();
				v.Normallize();
				bullet->SetDirection(v);
				bullet->SetPosition(_revolverTrans->GetWorldPos());
				bullet->_isActive = true;

				break;
			}
		}
	}
}
