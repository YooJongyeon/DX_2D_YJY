#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_adventure = make_shared <Adventure>();
	
	_anagle = make_shared <Texture>(L"Resource/purpleaiming.png");

	
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{
	_adventure->Update();
	_anagle->Update();
	_anagle->GetTransform()->GetPos() = MOUSE_POS;
}

void DungreedScene::Render()
{
	_adventure->Render();
	_anagle->Render();
}



