#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	/*_adventure = make_shared <Texture>(L"Resource/adventure.png");*/
	_adventure = make_shared <Adventure>();
	_revolver = make_shared <Texture>(L"Resource/revolver.png");
	_anagle = make_shared <Texture>(L"Resource/purpleaiming.png");

	//_revolver->GetTransform()->SetParent(_adventure->GetTransform()->GetMatrix());
	_revolver->GetTransform()->GetPos().x = 50;

	for (int i = 0; i < 30; i++)
	{
		shared_ptr<Bullet> temp = make_shared<Bullet>();
		_bulletPool.push_back(temp);
	}
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	_anagle->GetTransform()->GetPos() = MOUSE_POS;
	

	/*if (KEY_PRESS('A'))
	{
		_adventure->GetTransform()->GetPos().x -= 100 * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_adventure->GetTransform()->GetPos().x += 100 * DELTA_TIME ;

	}

	if (KEY_PRESS('W'))
	{
		_adventure->GetTransform()->GetPos().y += 100 * DELTA_TIME;

	}

	if (KEY_PRESS('S'))
	{
		_adventure->GetTransform()->GetPos().y -= 100 * DELTA_TIME;

	}*/

	if (KEY_Down(VK_LBUTTON))
	{
		FireBullet();
	}

	float angle1 = (MOUSE_POS - _revolver->GetTransform()->m_pos).Angle();
	_revolver->GetTransform()->GetAnagle()= angle1 - PI * 0.25f;

	_adventure->Update();
	_revolver->Update();
	_anagle->Update();

	for (auto& bullet : _bulletPool)
	{
		bullet->Update();
	}
}

void DungreedScene::Render()
{
	_adventure->Render();
	_revolver->Render();
	_anagle->Render();

	for (auto& bullet : _bulletPool)
	{
		bullet->Render();
	}
}

void DungreedScene::FireBullet()
{
	for (auto& bullet : _bulletPool)
	{
		if (bullet->_isActive == false)
		{
			Vector2 moveVec = MOUSE_POS - _revolver->GetTransform()->m_pos;
			moveVec.Normallize();
			bullet->SetPosition(_revolver->GetTransform()->m_pos);
			bullet->SetMovePostion(moveVec);
			bullet->_isActive = true;

			break;
		}
	}
}

