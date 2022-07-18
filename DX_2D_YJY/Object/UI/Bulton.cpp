#include "framework.h"
#include "Bulton.h"

Bulton::Bulton()
{
	_quad = make_shared <Quad>(L"Resource/Button.png");
	_quad->SetParent(Camera::GetInstance()->GetTransform());

	_col = make_shared<RectCollider>(_quad->GetHalfSize());
	_col->SetParent(_quad->GetTransform());
}

Bulton::~Bulton()
{
}

void Bulton::Update()
{
	_quad->Update();
	_col->Update();
}

void Bulton::PostRender()
{
	_quad->Render();
	_col->Render();

	{
		wstring text = StringToWsttring(_text);
		float offSetX = _quad->GetHalfSize().x * _quad->GetTransform()->GetScale().x *0.5f;
		float offSetY = _quad->GetHalfSize().y * _quad->GetTransform()->GetScale().y *0.5f;
		float sizeX = _quad->GetHalfSize().x * _quad->GetTransform()->GetScale().x;
		float sizeY = _quad->GetHalfSize().y * _quad->GetTransform()->GetScale().y;

		float left = _textPos.x - sizeX + offSetX;
		float top = _textPos.y - sizeY + offSetY;
		float right = _textPos.x + sizeX + offSetX;
		float bottom = _textPos.y + sizeY + offSetY;
		RECT rect = { left,top,right,bottom };
		DirectWrite::GetInstance()->RenderText(text, rect);
	}

}

void Bulton::SetPosition(Vector2 pos)
{
	_quad->GetTransform()->GetPos() = pos;
	_textPos = pos;
}

void Bulton::SetScale(Vector2 scale)
{
	_quad->GetTransform()->GetScale() = scale;
}

void Bulton::SeText(string text)
{
	_text = text;
}
