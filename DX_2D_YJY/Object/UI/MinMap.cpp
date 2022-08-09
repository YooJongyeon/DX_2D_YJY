#include "framework.h"
#include "MinMap.h"

MinMap::MinMap(Vector2 size)
	:_size(size)
{
	// RenderTarget
	_rtv = make_shared<RenderTarget>(size.x, size.y);
	_targetTexture = make_shared<Quad>(L"RenderTarget", size);
	shared_ptr<Texture> texture = Texture::Add(L"Target", _rtv->GetSRV());
	_targetTexture->SetTexture(texture);
	_targetTexture->GetTransform()->GetPos() = { WIN_WIDTH - size.x * 0.5f - 50.0f ,  WIN_HEIGHT - size.y * 0.5f - 50.0f };
	_targetTexture->Update();

	_miniPlayer = make_shared<Quad>(L"Resource/adventure.png");
	_miniPlayer->GetTransform()->GetScale() *= 0.1f;
	_miniPlayer->GetTransform()->GetPos() = _targetTexture->GetTransform()->GetPos();
}

MinMap::~MinMap()
{
}

void MinMap::Update()
{
	float backGroundX = _rightTop.x - _leftBottom.x;
	float backGroundY = _rightTop.y - _leftBottom.y;

	Vector2 ratio;
	ratio.x = _playerPos->x / backGroundX;
	ratio.y = _playerPos->y / backGroundY;

	_miniPlayer->GetTransform()->GetPos().x = _targetTexture->LeftBottom().x + ratio.x * _size.x;
	_miniPlayer->GetTransform()->GetPos().y = _targetTexture->LeftBottom().y + ratio.y * _size.y;

	_miniPlayer->Update();
}

void MinMap::SetRTV()
{
	_rtv->Set();
}

void MinMap::PostRender()
{
	_targetTexture->Render();
	_miniPlayer->Render();
}
