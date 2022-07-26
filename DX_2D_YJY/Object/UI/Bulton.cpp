#include "framework.h"
#include "Bulton.h"

Bulton::Bulton()
{
	_quad = make_shared <Quad>(L"Resource/Button.png", L"Shaders/TextureVertexShader.hlsl", L"Shaders/ButtonPixelShader.hlsl");
	_quad->SetParent(Camera::GetInstance()->GetTransform());

	_col = make_shared<RectCollider>(_quad->GetHalfSize());
	_col->SetParent(_quad->GetTransform());

	_buttonBuffer = make_shared<ButtonBuffer>();
	_buttonBuffer->data.state = 0;
	_buttonBuffer->data.hovered = 0.3f;
	_buttonBuffer->data.clicked = 0.5f;
}

Bulton::~Bulton()
{
}

void Bulton::Update()
{
	_quad->Update();
	_col->Update();
	SetState();
}

void Bulton::PostRender()
{
	_buttonBuffer->SetPSBuffer(0);
	_quad->Render();
	//_col->Render();

	{
		wstring text = StringToWsttring(_text);
		float offSetX = _quad->GetHalfSize().x * _quad->GetTransform()->GetScale().x *0.5f +15.0f;
		float offSetY = _quad->GetHalfSize().y * _quad->GetTransform()->GetScale().y *0.5f;
		float sizeX = _quad->GetHalfSize().x * _quad->GetTransform()->GetScale().x;
		float sizeY = _quad->GetHalfSize().y * _quad->GetTransform()->GetScale().y;

		float left = _textPos.x - sizeX + offSetX;
		float top = WIN_HEIGHT -_textPos.y - sizeY + offSetY;
		float right = _textPos.x + sizeX + offSetX;
		float bottom = WIN_HEIGHT- _textPos.y + sizeY + offSetY;
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

void Bulton::SetState()
{
	if (_col->IsCollision(MOUSE_WORLDPOS))
	{
		_stae = HOVER;

		if (KEY_PRESS(VK_LBUTTON))
		{
			_stae = CLICK;
		}
		if (KEY_PRESS(VK_LBUTTON))
		{
			if (_callBack != nullptr)
			{
				_callBack();
			}
			if (_callBackParam != nullptr)
			{
				_callBackParam(10);
			}
		}

	}
	else
	{
		_stae = NONE;
	}

	switch (_stae)
	{
	case Bulton::NONE:
		_buttonBuffer->data.state = 0;
		break;
	case Bulton::HOVER:
		_buttonBuffer->data.state = 1;
		break;
	case Bulton::CLICK:
		_buttonBuffer->data.state = 2;
		break;
	default:
		break;
	}
}


