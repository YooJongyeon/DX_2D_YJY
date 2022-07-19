#include "framework.h"
#include "Character.h"

Character::Character()
{
	_sprite = make_shared<Sprite>(L"Resource/Player/player_idle.png", Vector2(10,8));
	_sprite->GetTransform()->GetPos() = Vector2(WIN_WIDTH, WIN_HEIGHT) * 0.5f;
	_collider = make_shared<RectCollider>(_sprite->GetHalfFrameSize());
	_collider->SetParent(_sprite->GetTransform());
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
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/Player/player_idle.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "F_IDLE"));
		clips.clear();

	}
}

void Character::Update()
{
}

void Character::Render()
{
}

void Character::PostRender()
{
}

void Character::SetPostion(float x, float y)
{
}

void Character::SetAnimation(State aniState)
{
}

void Character::ZeldMoveByKeyBoard()
{
}

void Character::SEltDLE()
{
}
