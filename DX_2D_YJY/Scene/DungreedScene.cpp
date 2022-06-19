#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_adventure = make_shared <Texture>(L"Resource/adventure.png");
	_revolver = make_shared <Texture>(L"Resource/revolver.png");
	_anagle = make_shared <Texture>(L"Resource/purpleaiming.png");

	_revolver->GetTransform()->GetPos().x = 50;
	_revolver->GetTransform()->SetParent(_adventure->GetTransform()->GetMatrix());

	_anagle->GetTransform()->GetPos().x = 250;

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
	_anagle->GetTransform()->GetPos().x = MOUSE_POS._x;
	_anagle->GetTransform()->GetPos().y = MOUSE_POS._y;
	if (KEY_PRESS('A'))
	{
		_adventure->GetTransform()->GetPos().x -= 100 * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_adventure->GetTransform()->GetPos().x += 100 * DELTA_TIME;

	}
	if (KEY_PRESS(VK_LBUTTON))
	{
		for (auto& bullet : _bulletPool)
		{
			if (bullet->_isActive == false)
			{
				bullet->_isActive = true;
				Vector2 moveVec = mousePos - _revolver->GetTransform()->m_pos;
				moveVec.Normallize();
				bullet->SetPosition(_revolver->GetTransform()->m_pos);
				bullet->SetMovePostion(moveVec);

				break;
			}
		}
	}

	float angle1 = (MOUSE_POS - _revolver->GetTransform()->m_pos).Angle();
	_revolver->GetTransform()->GetAnagle() = angle1 - PI * 0.01f;

	int temp = Time::GetInstance()->GetFPS();
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
	ALPHA_STATE->SetState();
	_adventure->Render();
	_revolver->Render();
	_anagle->Render();

	for (auto& bullet : _bulletPool)
	{
		bullet->Render();
	}
}
