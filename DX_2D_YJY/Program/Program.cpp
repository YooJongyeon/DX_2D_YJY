#include "framework.h"
#include "Program.h"

#include "../Scene/TextureScene.h"
#include "../Scene/TextureWVPScene.h"

Program::Program()
{
	_scene = make_shared<TextureWVPScene>();
}

Program::~Program()
{
}

void Program::Update()
{
	_scene->Update();
}

void Program::Render()
{
	Device::GetInstance()->Clear();

	_scene->Render();

	Device::GetInstance()->Present();
}
