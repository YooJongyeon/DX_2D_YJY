#include "framework.h"
#include "TextureScene.h"

TextureScene::TextureScene()
{
	_quad = make_shared<Quad>(L"Resource/Fatalis.png");
}

TextureScene::~TextureScene()
{
}

void TextureScene::Update()
{
	_quad->Update();
}

void TextureScene::Render()
{
	_quad->Render();
}
