#include "framework.h"
#include "TextureWVPScene.h"
TextureWVPScene::TextureWVPScene()
{
	_quad = make_shared<Quad>(L"Resource/Fatalis.png");

	_worldBuffer = make_shared<MatrixBuffer>();
	

}

TextureWVPScene::~TextureWVPScene()
{
}

void TextureWVPScene::Update()
{

	/*if (GetAsyncKeyState(VK_F1))
	{
		_texture->GetScale().x += 0.001f;

	}
	if (GetAsyncKeyState(VK_F2))
	{
		_texture->GetScale().y += 0.001f;
	}

	if (GetAsyncKeyState(VK_F3))
	{
		_texture->GetScale().x -= 0.001f;
	}

	if (GetAsyncKeyState(VK_F4))
	{
		_texture->GetScale().y -= 0.001f;
	}




	if (GetAsyncKeyState(VK_SPACE))
	{
		_texture->GetAnagle() += 0.001f;
	}

	if (GetAsyncKeyState(VK_SHIFT))
	{
		_texture->GetAnagle() -= 0.001f;
	}



	if (GetAsyncKeyState(VK_LEFT))
	{
		_texture->GetPos().x -= 0.1f;
	}
	if (GetAsyncKeyState(VK_RIGHT))
	{
		_texture->GetPos().x += 0.1f;
	}

	if (GetAsyncKeyState(VK_UP))
	{
		_texture->GetPos().y += 0.1f;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{
		_texture->GetPos().y -= 0.1f;
	}*/


	

	_quad->Update();
}

void TextureWVPScene::Render()
{
	_worldBuffer->SetVSBuffer(0);
	
	_quad->Render();
}
