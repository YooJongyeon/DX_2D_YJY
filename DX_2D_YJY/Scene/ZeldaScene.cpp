#include "framework.h"
#include "ZeldaScene.h"

ZeldaScene::ZeldaScene()
{
	_zelda = make_shared<Zelda>();
}

ZeldaScene::~ZeldaScene()
{
}

void ZeldaScene::Update()
{
	_zelda->Update();
	
	if (KEY_Down('W'))
	{
		_zelda->SetB_RUN();
		_zelda->SetB_IDLE();
	} 
	if (KEY_Down('D'))
	{
		_zelda->SetR_RUN();
		_zelda->SetR_IDLE();
	} 
	if (KEY_Down('A'))
	{
		_zelda->SetL_RUN();
		_zelda->SetL_IDLE();
	} 
	if (KEY_Down('S'))
	{
		_zelda->SetF_RUN();
		_zelda->SetF_IDLE();
	}
	

}

void ZeldaScene::Render()
{
	_zelda->Render();
}

void ZeldaScene::PostRender()
{
	_zelda->PostRender();
}

