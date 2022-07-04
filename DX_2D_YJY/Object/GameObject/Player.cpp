#include "framework.h"
#include "Player.h"

Player::Player()
{
	_quad = make_shared <Quad>(L"Resource/adventure.png");
	_quad->GetTransform()->GetScale() = { 0.5f, 0.5f };


	_revolverTrans = make_shared<Transform>();
	_revolverTrans->SetParent(_quad->GetTransform());
	_revolverTrans->GetPos().x = _quad->GetHalfSize().x;

	_revolver = make_shared <Revolver>();
	_revolver->SetPlayer(_revolverTrans);


	_bullet.reserve(30);
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Bullet> temp = make_shared<Bullet>();
		temp->_isActive = false;
		_bullet.push_back(temp);
	}
	_collider = make_shared<RectCollider>(_quad->GetHalfSize());
	_collider->SetParent(_quad->GetTransform());
}

Player::~Player()
{
}

void Player::Update()
{
	Move();
	Aiming();
	Fire();

	_quad->Update();
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
	_quad->Render();
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
		_quad->GetTransform()->GetPos().x -= 100 * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_quad->GetTransform()->GetPos().x += 100 * DELTA_TIME;
	}

	if (KEY_PRESS('W'))
	{
		_quad->GetTransform()->GetPos().y += 100 * DELTA_TIME;
	}

	if (KEY_PRESS('S'))
	{
		_quad->GetTransform()->GetPos().y -= 100 * DELTA_TIME;
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
