#include "framework.h"
#include "Character.h"

Character::Character()
{
	_sprite = make_shared<Sprite>(L"Resource/Player/player_idle.png",Vector2(5,1));
	_sprite->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.5f;
	_sprite->GetTransform()->GetScale() = { 5.0f, 5.0f };

	_sprite2 = make_shared<Sprite>(L"Resource/Player/player_run.png", Vector2(5, 1));
	_sprite2->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.5f;
	_sprite2->GetTransform()->GetScale() = { 5.0f, 5.0f };

	_collider = make_shared<RectCollider>(_sprite->GetHalfFrameSize());
	_collider->SetParent(_sprite->GetTransform());

	CreateActions();
}

Character::~Character()
{
}

void Character::CreateActions()
{
	_actions.reserve(8);

	{
	 	vector<Action::Clip> clips;
		float w = 75.0f /5.0f;
		float h = 20.0f;
		
		float y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			
		}
		_actions.push_back(make_shared<Action>(clips, "F_IDLE"));
		clips.clear();

		w = 136.0f / 8.0f;
		h = 20.0f;

		y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));
			clips.emplace_back(0 + w * 5, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));
			clips.emplace_back(0 + w * 6, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));
			clips.emplace_back(0 + w * 7, y, w, h, Texture::Add(L"Resource/Player/player_run.png"));

		}
		_actions.push_back(make_shared<Action>(clips, "F_RUN"));
		clips.clear();
	}


	for (auto& action : _actions)
		action->Pause();

	_actions[_aniState]->Play();
}

void Character::Update()
{
	_sprite->Update();
	_sprite2->Update();
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

void Character::Render()
{
	_sprite->Render();
	_sprite2->Render();
	_collider->Render();
}

void Character::PostRender()
{
	_collider->Render();
}

void Character::SetPostion(float x, float y)
{
	_sprite->GetTransform()->GetPos() = { x,y };
	_sprite2->GetTransform()->GetPos() = { x,y };
	_CharacterPos = { x,y };
}

void Character::SetAnimation(State aniState)
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

void Character::ZeldMoveByKeyBoard()
{
	this->SetPostion(_CharacterPos.x, _CharacterPos.y);

	if (KEY_PRESS('D'))
	{
		_CharacterPos.x += 150 * DELTA_TIME;
		this->SetAnimation(Character::State::F_RUN);
		return;
	}
	

	SEltDLE();
}

void Character::SEltDLE()
{
	
	switch (_aniState)
	{
	case Character::F_RUN:
		SetAnimation(State::F_IDLE);
		break;
	default:
		break;
	}
	

}
