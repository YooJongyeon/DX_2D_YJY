#include "framework.h"
#include "Bulton.h"

Bulton::Bulton()
{
	_stae = Bulton::BultonState::NONE;

	_quad = make_shared<Quad>(L"Resource/Button.png", L"Shaders/TextureVertexShader.hlsl", L"Shaders/ButtonPixelShader.hlsl");
	
	_col = make_shared<RectCollider>(_quad->GetHalfSize());
	_col->SetParent(_quad->GetTransform());

	_buttonBuffer = make_shared<ButtonBuffer>();
	_buttonBuffer->data.state = 0;
	_buttonBuffer->data.hovered = 0.3f;
	_buttonBuffer->data.clicked = 0.5f;

#pragma region 버튼과 버튼 쉐이더
	//1. 버튼
	//	- quad : 이미지
	//	- col : 마우스가 버튼 위에 올라와있는지
	//	- text : 버튼에 이미지만 있으면 심심하니까dw

	//	2. Quad를 생성하고 그릴 때 픽셀셰이더를 건드려서 색깔을 바꿔야함
	//	- 어떤 식으로 바꿀거냐 ?
	//	= > 이 quad가 마우스가 올려져있나 ? , 클릭이 되어있냐 ?
	//	->CPU에서 이루어져야겠다.
	//	->GPU에 이 정보를 전달("ButtonBuffer")
	//	->GPU에서 정보를 전달 받게끔 설정("ButtonPixelShader")
#pragma endregion 
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
	_col->Render();

	{
		wstring text = StringToWsttring(_text);
		float offSetX = _quad->GetHalfSize().x * 0.5f;
		float offSetY = _quad->GetHalfSize().y * 0.5f;
		float sizeX = _quad->GetHalfSize().x;
		float sizeY = _quad->GetHalfSize().y;

		float left = _textPos.x - sizeX + offSetX;
		float top = WIN_HEIGHT - _textPos.y - sizeY + offSetY;
		float right = _textPos.x + sizeX + offSetX;
		float bottom = WIN_HEIGHT - _textPos.y + sizeY + offSetY;
		RECT rect = { left,top, right, bottom };
		DirectWrite::GetInstance()->RenderText(text, rect);
	}

	ImGui::SliderFloat("HoverColor", &_buttonBuffer->data.hovered, 0.0f, 1.0f);
	ImGui::SliderFloat("ClickColor", &_buttonBuffer->data.clicked, 0.0f, 1.0f);

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

void Bulton::SetText(string text)
{
	_text = text;
}

void Bulton::SetState()
{
	if (_col->IsCollision(MOUSE_POS))
	{
		_stae = HOVER;

		if (KEY_PRESS(VK_LBUTTON))
		{
			_stae = CLICK;
		}

		if (KEY_Up(VK_LBUTTON))
		{
			if (_callBack != nullptr)
				_callBack();

			if (_callBackParam != nullptr)
				_callBackParam(_param);
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


