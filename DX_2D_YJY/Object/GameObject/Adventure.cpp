#include "framework.h"
#include "Adventure.h"

Adventure::Adventure()
{
	_texture = make_shared <Texture>(L"Resource/adventure.png");
	_texture->GetTransform()->GetScale() = { 0.5f, 0.5f };

	
	_revolverTrans = make_shared<Transform>();
	_revolverTrans->SetParent(_texture->GetTransform()->GetMatrix());
	_revolverTrans->GetPos()._x = 50;

	_revolver = make_shared <Revolver>();
	_revolver->SetPlayer(_revolverTrans);

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Bullet> temp = make_shared<Bullet>();
		_bullet.push_back(temp);
	}
}

Adventure::~Adventure()
{
}

void Adventure::Update()
{
	Move();
	Aiming();
	Fire();

	_texture->Update();
	_revolver->Update();
	_revolverTrans->UpdateWorldBuffer();

	for (auto& bullet : _bullet)
	{
		bullet->Update();
	}
}

void Adventure::Render()
{
	
	_texture->Render();
	_revolver->Render();

	for (auto& bullet : _bullet)
	{
		bullet->Render();
	}
}

void Adventure::Move()
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

void Adventure::Aiming()
{
	Vector2 v = MOUSE_POS - _revolverTrans->GetWorldPos();
	float angle = v.Angle();
	_revolverTrans->GetAnagle() = angle;
}

void Adventure::Fire()
{
	if (KEY_Down(VK_LBUTTON))
	{
		for (auto& bullet : _bullet)
		{
			if (bullet ->_isActive == false)
			{
				bullet->_isActive = true;
				Vector2 v = MOUSE_POS - _revolverTrans->GetWorldPos();
				v.Normallize();
				bullet->SetDirection(v);
				bullet->SetPosition(_revolverTrans->GetWorldPos());

				break;
			}

		}	
	}

}
