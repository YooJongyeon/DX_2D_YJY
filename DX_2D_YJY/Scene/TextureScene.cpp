#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_quad = make_shared<Quad>(L"Resource/Fatalis.png");	_quad->GetTransform()->GetPos() = CENTER;

	_filterBuffer = make_shared<FilterBuffer>();
	_filterBuffer->data.selected = 1; // ¿ÞÂÊ
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	_filterBuffer->SetPSBuffer(0);
	_quad->Update();
}

void TextureScene::Render()
{
	_filterBuffer->SetPSBuffer(0);
	_quad->Render();
}

void TextureScene::PostRender()
{
	ImGui::SliderInt("Left Right", &_filterBuffer->data.selected, 0, 1);
}
