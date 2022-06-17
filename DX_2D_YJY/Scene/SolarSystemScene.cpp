#include "framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	_sun = make_shared <Texture>(L"Resource/sun.PNG");
	_earth = make_shared <Texture>(L"Resource/earth.PNG");
	_moon = make_shared <Texture>(L"Resource/moon.PNG");

	_sun->GetTransform()->GetScale().x *= 1.3f;
	_sun->GetTransform()->GetScale().y *= 1.3f;

	_earth->GetTransform()->SetParent(_sun->GetTransform()->GetMatrix());
	_earth->GetTransform()->GetPos().x = 250;
	_earth->GetTransform()->GetScale().x *= 0.8f;
	_earth->GetTransform()->GetScale().y *= 0.8f;

	_moon->GetTransform()->SetParent(_earth->GetTransform()->GetMatrix());
	_moon->GetTransform()->GetPos().x = 150;
	_moon->GetTransform()->GetScale().x *= 0.8f;
	_moon->GetTransform()->GetScale().y *= 0.8f;

	
}

SolarSystemScene::~SolarSystemScene()
{
}

void SolarSystemScene::Update()
{

	_sun->GetTransform()->GetPos().x = MOUSE_POS._x;
	_sun->GetTransform()->GetPos().y = MOUSE_POS._y;
	if (KEY_PRESS(VK_SPACE))
	{
		_sun->GetTransform()->GetAnagle() += 1 * DELTA_TIME; // DELTA_TIME : 1Tick당 걸리는 시간
		_earth->GetTransform()->GetAnagle() += 1 * DELTA_TIME;
		_moon->GetTransform()->GetAnagle() += 1 * DELTA_TIME;
	}

	int temp = Time::GetInstance()->GetFPS();

	_sun->Update();
	_earth->Update();
	_moon->Update();

}

void SolarSystemScene::Render()
{
	ALPHA_STATE->SetState();
	_sun->Render();
	_earth->Render();
	_moon->Render();
}
