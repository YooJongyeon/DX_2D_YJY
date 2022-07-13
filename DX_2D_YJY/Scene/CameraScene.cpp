#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	_backGround = make_shared<Quad>(L"Resource/LostArk.png");

	_zelda = make_shared<Zelda>();

	_zeldaFollowTrans = make_shared<Transform>();

	Camera::GetInstance()->SetTarget(_zeldaFollowTrans);
	Vector2 leftBottom = { -_backGround->GetHalfSize().x, -_backGround->GetHalfSize().y };
	Vector2 rightTop = { _backGround->GetHalfSize().x, _backGround->GetHalfSize().y };
	Camera::GetInstance()->SetLeftBottom(leftBottom);
	Camera::GetInstance()->SetRightTop(rightTop);
}

CameraScene::~CameraScene()
{
}

void CameraScene::Update()
{
	ZeldaMove();

	_backGround->Update();
	_zelda->Update();

	float distance = _zelda->GetTransform()->GetPos().Distance(_zeldaFollowTrans->GetPos());
	if (distance >= 30.0f)
	{
		_zeldaFollowTrans->GetPos() = LERP(_zeldaFollowTrans->GetPos(), _zelda->GetTransform()->GetPos(), 0.001f);
	}

}

void CameraScene::Render()
{
	_backGround->Render();
	_zelda->Render();
}

void CameraScene::PostRender()
{
}

void CameraScene::ZeldaMove()
{

	_zelda->SetPostion(_zeldaPos.x, _zeldaPos.y);

	if (KEY_PRESS('W'))
	{
		_zeldaPos.y += 150 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::B_RUN);

		return;
	}

	if (KEY_PRESS('A'))
	{
		_zeldaPos.x -= 150 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::L_RUN);

		return;
	}

	if (KEY_PRESS('S'))
	{
		_zeldaPos.y -= 150 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::F_RUN);

		return;
	}

	if (KEY_PRESS('D'))
	{
		_zeldaPos.x += 150 * DELTA_TIME;
		_zelda->SetAnimation(Zelda::State::R_RUN);

		return;
	}


}
