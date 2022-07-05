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
		shared_ptr<Action> frontIDLE = make_shared<Action>(clips, "F_IDLE");
		_actions.push_back(frontIDLE);
		clips.clear();

		// 왼 가만히
		y = 1040.0f * (1.0f / 8.0f);
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		shared_ptr<Action> leftIDLE = make_shared<Action>(clips, "L_IDLE");
		_actions.push_back(leftIDLE);
		clips.clear();

		// 뒤 가만히
		y = 1040.0f * (2.0f / 8.0f);
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		shared_ptr<Action> backIDLE = make_shared<Action>(clips, "B_IDLE");
		_actions.push_back(backIDLE);
		clips.clear();

		// 오 가만히
		y = 1040.0f * (3.0f / 8.0f);
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/zelda.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/zelda.png"));
		}
		shared_ptr<Action> rightIDLE = make_shared<Action>(clips, "R_IDLE" );
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
		shared_ptr<Action> frontRUN = make_shared<Action>(clips, "F_RUN", Action::END);
		// 진짜 중요
		frontRUN->SetEndEvent(std::bind(&Zelda::SetFrontMessage, this));
		_actions.push_back(frontRUN);
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
		shared_ptr<Action> leftRUN = make_shared<Action>(clips, "L_RUN", Action::END);
		// 진짜 중요
		leftRUN->SetEndEvent(std::bind(&Zelda::SetLeftMessage, this));
		_actions.push_back(leftRUN);
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
		shared_ptr<Action> backRUN = make_shared<Action>(clips, "B_RUN", Action::END);
		// 진짜 중요
		backRUN->SetEndEvent(std::bind(&Zelda::SetBackMessage, this));
		_actions.push_back(backRUN);
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
		shared_ptr<Action> rightRUN = make_shared<Action>(clips, "R_RUN", Action::END);
		// 진짜 중요
		rightRUN->SetEndEvent(std::bind(&Zelda::SetRightMessage, this));
		_actions.push_back(rightRUN);
		clips.clear();

	}

	for (auto& action : _actions)
		action->Pause();

	
}

void Zelda::Update()
{
	_sprite->Update();
	Move();

	for (auto& action : _actions)
	{
		action->Update();
		if (!action->IsPlay())
			continue;
		_sprite->SetClip(action->GetCurClip());
	}
}

void Zelda::Render()
{
	_sprite->Render();
}

void Zelda::PostRender()
{
	ImGui::Text(_message.data());
}

void Zelda::SetPostion(float x, float y)
{
	// 과제
	// 멤버변수 만들고 
	//ImGui::SliderInt("ZeldaAction", &int, 0, 7);

}

void Zelda::SetAnimation(State aniState)
{
	for (auto& action : _actions)
	{
		action->Stop();
	}
	_actions[aniState]->Play();
}

void Zelda::Move()
{
	if (KEY_PRESS('A'))
	{
		_sprite->GetTransform()->GetPos().x -= 100 * DELTA_TIME;
	}

	if (KEY_PRESS('D'))
	{
		_sprite->GetTransform()->GetPos().x += 100 * DELTA_TIME;
	}

	if (KEY_PRESS('W'))
	{
		_sprite->GetTransform()->GetPos().y += 100 * DELTA_TIME;
	}

	if (KEY_PRESS('S'))
	{
		_sprite->GetTransform()->GetPos().y -= 100 * DELTA_TIME;
	}
}


