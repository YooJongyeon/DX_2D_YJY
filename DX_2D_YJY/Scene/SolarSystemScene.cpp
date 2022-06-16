#include "framework.h"
#include "SolarSystemScene.h"

SolarSystemScene::SolarSystemScene()
{
	_sun = make_shared <Texture>(L"Resource/sun.PNG");
	_earth = make_shared <Texture>(L"Resource/earth.PNG");
	_moon = make_shared <Texture>(L"Resource/moon.PNG");
	_sun->GetScale().x *= 1.3f;
	_sun->GetScale().y *= 1.3f;

	_earth->SetParent(_sun->GetMatrix());
	_earth->GetPos().x = 250;
	_earth->GetScale().x *= 0.8f;
	_earth->GetScale().y *= 0.8f;

	_moon->SetParent(_earth->GetMatrix());
	_moon->GetPos().x = 150;
	_moon->GetScale().x *= 0.8f;
	_moon->GetScale().y *= 0.8f;

	_samplerState = make_shared<SamplerState>();
	_blendState = make_shared<BlendState>();
}

SolarSystemScene::~SolarSystemScene()
{
}

void SolarSystemScene::Update()
{

	_sun->GetPos().x = MOUSE_POS._x;
	_sun->GetPos().y = MOUSE_POS._y;
	if (KEY_PRESS(VK_SPACE))
	{
		_sun->GetAnagle() += 1 * DELTA_TIME; // DELTA_TIME : 1Tick당 걸리는 시간
		_earth->GetAnagle() += 1 * DELTA_TIME;
		_moon->GetAnagle() += 1 * DELTA_TIME;
	}



	int temp = Time::GetInstance()->GetFPS();

	_sun->Update();
	_earth->Update();
	_moon->Update();

}

void SolarSystemScene::Render()
{
	//_samplerState->PSSet(0);
	_blendState->Additive();
	_blendState->SetState();

	_sun->Render();
	_earth->Render();
	_moon->Render();

}
