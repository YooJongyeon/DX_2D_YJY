#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/TextureWVPScene.h"
#include "../Scene/SolarSystemScene.h"
Program::Program()
{
	_scene = make_shared<SolarSystemScene>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectionBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projection = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectionBuffer->SetMatrix(projection);

	Time::GetInstance()->SetFPS(60);
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
	_projectionBuffer->Update();
	_viewBuffer->Update();

	int temp = Time::GetInstance()->GetFPS();
}

void Program::Render()
{
	_viewBuffer->SetVSBuffer(1);
	_projectionBuffer->SetVSBuffer(2);
	Device::GetInstance()->Clear();

	_scene->Render();

	Device::GetInstance()->Present();
}
