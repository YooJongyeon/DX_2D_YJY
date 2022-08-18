#include "framework.h"
#include "ZeldaScene.h"

ZeldaScene::ZeldaScene()
{
	_zelda = make_shared<Zelda>();
	_zeldaPos = { WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f };
	_zelda->SetPostion(WIN_WIDTH * 0.5f, WIN_HEIGHT * 0.5f);


	_button = make_shared <Bulton>();
	_button->SetScale(Vector2(0.1f, 0.1f));
	_button->SetText("Next");
	_button->SetPosition(CENTER);
	_button->SetEvent(std::bind(&ZeldaScene::NextScene, this));
}

ZeldaScene::~ZeldaScene()
{
}

void ZeldaScene::Update()
{
	ZeldaMove();
	_zelda->Update();

	_zelda->SetPostion(_zeldaPos.x, _zeldaPos.y);
}

void ZeldaScene::Render()
{
	_zelda->Render();
}

void ZeldaScene::PostRender()
{
	_zelda->PostRender();
}

void ZeldaScene::ZeldaMove()
{
	if (KEY_PRESS('W'))
	{
		_zeldaPos.y += 50 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::B_RUN);

		return;
	}

	if (KEY_PRESS('A'))
	{
		_zeldaPos.x -= 50 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::L_RUN);

		return;
	}

	if (KEY_PRESS('S'))
	{
		_zeldaPos.y -= 50 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::F_RUN);

		return;
	}

	if (KEY_PRESS('D'))
	{
		_zeldaPos.x += 50 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::R_RUN);

		return;
	}

}

void ZeldaScene::NextScene()
{
	SCENE->SetScene("Dungreed");
}

