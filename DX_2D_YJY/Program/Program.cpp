#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/TextureWVPScene.h"
#include "../Scene/SolarSystemScene.h"
#include "../Scene/DungreedScene.h"
#include "../Scene/ColliderScene.h"
#include "../Scene/ZeldaScene.h"
#include "../Scene//FillterScene.h"
#include "../Scene/EffectScene.h"
#include "../Scene/CameraScene.h"
#include "../Scene/TestScene.h"
Program::Program()
{
	_scene = make_shared<TestScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	EffectManager::GetInstance()->Update();
	Camera::GetInstance()->Update();

	_scene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ALPHA_STATE->SetState();

	Camera::GetInstance()->SetViewPort();
	Camera::GetInstance()->SetProjectionBuffer();


	_scene->RreRender();

	_scene->Render();
	EffectManager::GetInstance()->Render();

	//ImGui::Text("FPS : %d", Time::GetInstance()->GetFPS());
	wstring fps = L"FPS : " + to_wstring((int)Time::GetInstance()->GetFPS());
	RECT rect = { 0,0,100,100 };

	DirectWrite::GetInstance()->GetDeviceContext()->BeginDraw();
	DirectWrite::GetInstance()->RenderText(fps, rect);


	Camera::GetInstance()->PostRender();
	_scene->PostRender();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	DirectWrite::GetInstance()->GetDeviceContext()->EndDraw();
	Device::GetInstance()->Present();
}
