#include "framework.h"
#include "DungreedScene.h"

DungreedScene::DungreedScene()
{
	_adventure = make_shared <Texture>(L"Resource/adventure.png");
	_revolver = make_shared <Texture>(L"Resource/revolver.png");
	_anagle = make_shared <Texture>(L"Resource/Angle.png");

	

	_revolver->GetTransform()->SetParent(_adventure->GetTransform()->GetMatrix());
	_revolver->GetTransform()->GetPos().x = 60;

	
	_anagle->GetTransform()->SetParent(_adventure->GetTransform()->GetMatrix());

	_anagle->GetTransform()->GetPos().x = 250;
}

DungreedScene::~DungreedScene()
{
}

void DungreedScene::Update()
{

	_anagle->GetTransform()->GetPos().x = MOUSE_POS._x;
	_anagle->GetTransform()->GetPos().y = MOUSE_POS._y;

	_revolver->GetTransform()->GetAnagle() =  MOUSE_POS._x;
	_revolver->GetTransform()->GetAnagle() =  MOUSE_POS._y ;

	if (KEY_PRESS('A'))
	{
		_adventure->GetTransform()->GetPos().x -= 100 * DELTA_TIME; 
	}

	if (KEY_PRESS('D'))
	{
		_adventure->GetTransform()->GetPos().x += 100 * DELTA_TIME; 
	}


	int temp = Time::GetInstance()->GetFPS();

	_adventure->Update();
	_revolver->Update();
	_anagle->Update();
}

void DungreedScene::Render()
{
	ALPHA_STATE->SetState();
	_adventure->Render();
	_revolver->Render();
	_anagle->Render();
}
