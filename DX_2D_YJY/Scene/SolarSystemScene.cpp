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
}

SolarSystemScene::~SolarSystemScene()
{
}

void SolarSystemScene::Update()
{
	_sun->GetAnagle() += 0.0001f; // /DELTA_TIME : 1Tick당 걸리는 시간
	_earth->GetAnagle() += 0.001f;
	_moon->GetAnagle() += 0.001f;

	_sun->Update();
	_earth->Update();
	_moon->Update();

}

void SolarSystemScene::Render()
{
	_sun->Render();
	_earth->Render();
	_moon->Render();

}
