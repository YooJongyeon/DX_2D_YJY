#include "framework.h"
#include "Character.h"

Character::Character()
{
	_sprite = make_shared<Sprite>(L"Resource/player_idle.png", Vector2(10,8));
	_sprite->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.5f;
	_sprite->GetTransform()->GetScale() = Vector2(20.0f, 20.0f);
	_collider = make_shared<RectCollider>(_sprite->GetHalfFrameSize());
	_collider->SetParent(_sprite->GetTransform());
	CreateActions();
}

Character::~Character()
{
}

void Character::CreateActions()
{
	_actions.reserve(2);
	{
		vector<Action::Clip> clips;
		float w = 75.0f / 5.0f;
		float h = 20.0f;

		float y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/player_idle.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/player_idle.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/player_idle.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/player_idle.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/player_idle.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "R_IDLE"));
		clips.clear();

	}
	for (auto& action : _actions)
		action->Pause();

	_actions[_aniState]->Play();
}

void Character::Update()
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

void Character::Render()
{
	_sprite->Render();
}

void Character::PostRender()
{
	_collider->Render();
}

void Character::SetPostion(float x, float y)
{
	_sprite->GetTransform()->GetPos() = { x,y };
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
	//this->SetPostion(_CharacterPos.x, _CharacterPos.y);

	//if (KEY_PRESS('A'))
	//{
	//	_CharacterPos.x -= 150 * DELTA_TIME;
	//	this->SetAnimation(Character::State::L_RUN);

	//	return;
	//}

	//if (KEY_PRESS('D'))
	//{
	//	_CharacterPos.x += 150 * DELTA_TIME;
	//	this->SetAnimation(Character::State::R_RUN);

	//	return;
	//}

	SEltDLE();
}

void Character::SEltDLE()
{
	switch (_aniState)
	{
	
	case Character::L_RUN:
		SetAnimation(State::L_IDLE);
		break;

	case Character::R_RUN:
		SetAnimation(State::R_IDLE);
		break;
	default:
		break;
	}

}
