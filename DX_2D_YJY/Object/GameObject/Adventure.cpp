#include "framework.h"
#include "Adventure.h"

Adventure::Adventure()
{
	_texture = make_shared <Texture>(L"Resource/adventure.png");
	_texture->GetTransform()->GetScale() = { 1.5f, 1.5f };

	
	_revolverTrans = make_shared<Transform>();
	_revolverTrans->SetParent(_texture->GetTransform()->GetMatrix());
	_revolverTrans->GetPos().x = 150;

	_revolver = make_shared <Revolver>();
	_revolver->SetPlayer(_revolverTrans);
}

Adventure::~Adventure()
{
}

void Adventure::Update()
{
	Move();
	_texture->Update();
	_revolver->Update();
	_revolverTrans->UpdateWorldBuffer();
}

void Adventure::Render()
{
	
	_texture->Render();
	_revolver->Render();

}

void Adventure::Move()
{
	if (KEY_PRESS('A'))
	{
		_texture->GetTransform()->GetPos().x -= 100 * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_texture->GetTransform()->GetPos().x += 100 * DELTA_TIME;

	}

	if (KEY_PRESS('W'))
	{
		_texture->GetTransform()->GetPos().y += 100 * DELTA_TIME;

	}

	if (KEY_PRESS('S'))
	{
		_texture->GetTransform()->GetPos().y -= 100 * DELTA_TIME;

	}
	
}

void Adventure::Aiming()
{
	Vector2 v = MOUSE_POS - _revolverTrans->GetWorldPos();

	float angle = v.Angle();

	_revolverTrans->GetAnagle() = angle;

	
	
}
