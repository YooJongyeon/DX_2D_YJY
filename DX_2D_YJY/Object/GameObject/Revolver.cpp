#include "framework.h"
#include "Revolver.h"

Revolver::Revolver()
{
	_quad = make_shared <Quad>(L"Resource/revolver.png");
	_quad->GetTransform()->GetScale() *= 1.0f;
}

Revolver::~Revolver()
{
}

void Revolver::Update()
{
	_quad->Update();
}

void Revolver::Render()
{
	_quad->Render();
}