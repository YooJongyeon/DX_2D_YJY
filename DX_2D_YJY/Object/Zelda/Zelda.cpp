#include "framework.h"
#include "Zelda.h"

Zelda::Zelda()
{
	_sprite = make_shared<Sprite>(L"Resource/zelda.png", Vector2(10, 8));
	_sprite->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.5f;
	_collider = make_shared<RectCollider>(_sprite->GetHalfFrameSize());
	_collider->SetParent(_sprite->GetTransform());

	CreateActions();
}

Zelda::~Zelda()
{
}

void Zelda::CreateActions()
{
	_actions.reserve(8);
	// Action 세팅
	{
		vector<Action::Clip> clips;
		float w = 1200.0f / 10.0f;
		float h = 1040.0f / 8.0f;

		// 앞 가만히
		float y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "F_IDLE"));
		clips.clear();

		// 왼 가만히
		y = 1040.0f * (1.0f / 8.0f);
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "L_IDLE"));
		clips.clear();

		// 뒤 가만히
		y = 1040.0f * (2.0f / 8.0f);
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "B_IDLE"));
		clips.clear();

		// 오 가만히
		y = 1040.0f * (3.0f / 8.0f);
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		shared_ptr<Action> rightIDLE = make_shared<Action>(clips, "R_IDLE");
		_actions.push_back(rightIDLE);
		clips.clear();

		y = 1040 * 0.5f;
		// 앞으로 달리기
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 5, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 6, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 7, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 8, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 9, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "F_RUN"));
		clips.clear();

		y = 1040 * (5.0f / 8.0f);
		// 왼으로 달리기
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 5, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 6, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 7, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 8, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 9, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "L_RUN"));
		clips.clear();

		y = 1040 * (6.0f / 8.0f);
		// 뒤로 달리기
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 5, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 6, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 7, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 8, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 9, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "B_RUN"));
		clips.clear();

		y = 1040 * (7.0f / 8.0f);
		// 오른 달리기
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 5, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 6, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 7, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 8, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 9, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		shared_ptr<Action> rightRUN = make_shared<Action>(clips, "R_RUN");
		// 진짜 중요
		//rightRUN->SetEndEvent(std::bind(&Zelda::SetMessage, this));
		_actions.push_back(rightRUN);
		clips.clear();

	}

	for (auto& action : _actions)
		action->Pause();

	_actions[_aniState]->Play();
}

void Zelda::Update()
{
	_sprite->Update();
	_collider->Update();

	ZeldMoveByKeyBoard();

	for (auto& action : _actions)
	{
		action->Update();
		if (!action->IsPlay())
			continue;
		_sprite->SetClipToActionBuffer(action->GetCurClip());
	}
}

void Zelda::Render()
{
	_sprite->Render();
}

void Zelda::PostRender()
{
	ImGui::Text(_message.data());
	_collider->Render();
}

void Zelda::SetPostion(float x, float y)
{
	_sprite->GetTransform()->GetPos() = { x,y };
	_zeldaPos = { x,y };
}

void Zelda::SetAnimation(State aniState)
{
	if (_actions[aniState]->IsPlay() && _actions[aniState]->GetAnimType() == Action::LOOP)
		return;

	for (auto& action : _actions)
	{
		if (action->IsPlay() && _aniState == aniState)
			continue;

		action->Reset();
	}

	_actions[aniState]->Play();
	_aniState = aniState;
}

void Zelda::ZeldMoveByKeyBoard()
{

	this->SetPostion(_zeldaPos.x, _zeldaPos.y);

	if (KEY_PRESS('W'))
	{
		_zeldaPos.y += 150 * DELTA_TIME;
		this->SetAnimation(Zelda::State::B_RUN);

		return;
	}

	if (KEY_PRESS('A'))
	{
		_zeldaPos.x -= 150 * DELTA_TIME;
		this->SetAnimation(Zelda::State::L_RUN);

		return;
	}

	if (KEY_PRESS('S'))
	{
		_zeldaPos.y -= 150 * DELTA_TIME;
		this->SetAnimation(Zelda::State::F_RUN);

		return;
	}

	if (KEY_PRESS('D'))
	{
		_zeldaPos.x += 150 * DELTA_TIME;
		this->SetAnimation(Zelda::State::R_RUN);

		return;
	}

	SEltDLE();
}

void Zelda::SEltDLE()
{
	switch (_aniState)
	{
	case Zelda::F_RUN:
		SetAnimation(State::F_IDLE);
		break;
	case Zelda::L_RUN:
		SetAnimation(State::L_IDLE);
		break;
	case Zelda::B_RUN:
		SetAnimation(State::B_IDLE);
		break;
	case Zelda::R_RUN:
		SetAnimation(State::R_IDLE);
		break;
	default:
		break;
	}

}

