#include "framework.h"
#include "Program.h"


Program::Program()
{
	srand(static_cast<unsigned int>(time(nullptr)));

}

Program::~Program()
{
}

void Program::Update()
{
	EffectManager::GetInstance()->Update();
	Camera::GetInstance()->Update();

	SCENE->Update();

}

void Program::Render()
{
	SCENE->PreRender();

	Device::GetInstance()->SetRenderTarget();
	Device::GetInstance()->Clear();

	ImGui_ImplDX11_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	ALPHA_STATE->SetState();

	Camera::GetInstance()->SetViewPort();
	Camera::GetInstance()->SetProjectionBuffer();

	SCENE->Render();
	EffectManager::GetInstance()->Render();

	//ImGui::Text("FPS : %d", Time::GetInstance()->GetFPS());
	wstring fps = L"FPS : " + to_wstring((int)Time::GetInstance()->GetFPS());
	RECT rect = { 0,0,100,100 };

	DirectWrite::GetInstance()->GetDeviceContext()->BeginDraw();
	DirectWrite::GetInstance()->RenderText(fps, rect);


	Camera::GetInstance()->PostRender();
	Camera::GetInstance()->SetUiBuffer();
	SCENE->PostRender();

	ImGui::Render();
	ImGui_ImplDX11_RenderDrawData(ImGui::GetDrawData());

	DirectWrite::GetInstance()->GetDeviceContext()->EndDraw();
	Device::GetInstance()->Present();
}
