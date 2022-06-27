#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_adventure = make_shared <Adventure>();
	_anagle = make_shared <Texture>(L"Resource/purpleaiming.png");
	_monster = make_shared <Monster>();
	
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	_adventure->Update();
	_anagle->Update();
	_monster->Update();

	if (_adventure->Getbullet()->IsCollision(_monster))
	{
		_adventure->Getbullet()->_isActive = false;
		_monster->_hp -= 10.0f;
		if (_monster->_hp <= 0)
			_monster->_isActive = false;
	}

	_anagle->GetTransform()->GetPos() = MOUSE_POS;
}

void DungreedScene::Render()
{

	_adventure->Render();
	_monster->Render();
	
	_anagle->Render();


}



