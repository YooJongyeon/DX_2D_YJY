#include "framework.h"
#include "TextureWVPScene.h"
TextureWVPScene::TextureWVPScene()
{
	_texture = make_shared<Texture>(L"Resource/Fatalis.png");

	_worldBuffer = make_shared<MatrixBuffer>();
	_viewBuffer = make_shared<MatrixBuffer>();
	_projectionBuffer = make_shared<MatrixBuffer>();

	XMMATRIX projection = XMMatrixOrthographicLH(WIN_WIDTH, WIN_HEIGHT, 0.0f, 1.0f);

	_projectionBuffer->SetMatrix(projection);
	_projectionBuffer->Update();
}

TextureWVPScene::~TextureWVPScene()
{
}

void TextureWVPScene::Update()
{

	if (GetAsyncKeyState(VK_F1))
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
	}

	_worldBuffer->Update();
	_viewBuffer->Update();

	_texture->Update();
}

void TextureWVPScene::Render()
{
	_worldBuffer->SetVSBuffer(0);
	_viewBuffer->SetVSBuffer(1);
	_projectionBuffer->SetVSBuffer(2);

	_texture->Render();
}
