#include "framework.h"
#include "Revolver.h"

Revolver::Revolver()
{
	_texture = make_shared <Texture>(L"Resource/revolver.png");
}

Revolver::~Revolver()
{
}

void Revolver::Update()
{
	_texture->Update();
}

void Revolver::Render()
{
	_texture->Render();
}
