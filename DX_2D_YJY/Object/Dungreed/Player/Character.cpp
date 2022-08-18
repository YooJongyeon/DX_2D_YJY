#include "framework.h"
#include "Character.h"

Character::Character()
{
	_spriteFrontIdle = make_shared<Sprite>(L"Resource/Player/player_idle.png",Vector2(5,1));
	_spriteFrontIdle->GetTransform()->GetScale() = { 2.0f, 2.0f };

	_spriteFrontRun = make_shared<Sprite>(L"Resource/Player/player_run.png", Vector2(8, 1));
	_spriteFrontRun->GetTransform()->GetScale() = { 2.0f, 2.0f };

	_spriteBackIdle = make_shared<Sprite>(L"Resource/Player/player_idle_left.png", Vector2(5, 1));
	_spriteBackIdle->GetTransform()->GetScale() = { 2.0f, 2.0f };

	_spriteBackRun = make_shared<Sprite>(L"Resource/Player/player_run_left.png", Vector2(8, 1));
	_spriteBackRun->GetTransform()->GetScale() = { 2.0f, 2.0f };

	_spriteJump = make_shared<Sprite>(L"Resource/Player/player_jump.png", Vector2(1, 1));
	_spriteJump->GetTransform()->GetScale() = { 2.0f, 2.0f };

	_frontIdleCollider = make_shared<RectCollider>(_spriteFrontIdle->GetHalfFrameSize());
	_frontIdleCollider->SetParent(_spriteFrontIdle->GetTransform());

	_frontRunCollider = make_shared<RectCollider>(_spriteFrontRun->GetHalfFrameSize());
	_frontRunCollider->SetParent(_spriteFrontRun->GetTransform());

	_backIdleCollider = make_shared<RectCollider>(_spriteBackIdle->GetHalfFrameSize());
	_backIdleCollider->SetParent(_spriteBackIdle->GetTransform());

	_backRunCollider = make_shared<RectCollider>(_spriteBackRun->GetHalfFrameSize());
	_backRunCollider->SetParent(_spriteBackRun->GetTransform());

	_jumpCollider = make_shared<RectCollider>(_spriteJump->GetHalfFrameSize());
	_jumpCollider->SetParent(_spriteJump->GetTransform());

	_weaponTrans = make_shared<Transform>();
	_weaponTrans->SetParent(_spriteFrontRun->GetTransform());

	_weaponTrans->GetPos().x = _spriteFrontRun->GetHalfFrameSize().x + 5 ;
	_weaponTrans->GetPos().y = _spriteFrontRun->GetHalfFrameSize().y - 10;

	_weaponTrans2 = make_shared<Transform>();
	_weaponTrans2->SetParent(_spriteBackRun->GetTransform());

	_weaponTrans2->GetPos().x = _spriteBackRun->GetHalfFrameSize().x + 5;
	_weaponTrans2->GetPos().y = _spriteBackRun->GetHalfFrameSize().y - 10;

	_weaponTrans3 = make_shared<Transform>();
	_weaponTrans3->SetParent(_spriteJump->GetTransform());

	_weaponTrans3->GetPos().x = _spriteJump->GetHalfFrameSize().x + 5;
	_weaponTrans3->GetPos().y = _spriteJump->GetHalfFrameSize().y - 10;


	_weaponTrans4 = make_shared<Transform>();
	_weaponTrans4->SetParent(_spriteFrontIdle->GetTransform());

	_weaponTrans4->GetPos().x = _spriteFrontIdle->GetHalfFrameSize().x + 5;
	_weaponTrans4->GetPos().y = _spriteFrontIdle->GetHalfFrameSize().y - 10;


	_weaponTrans5 = make_shared<Transform>();
	_weaponTrans5->SetParent(_spriteBackIdle->GetTransform());

	_weaponTrans5->GetPos().x = _spriteBackIdle->GetHalfFrameSize().x + 5;
	_weaponTrans5->GetPos().y = _spriteBackIdle->GetHalfFrameSize().y - 10;

	_weapon = make_shared<Weapon>();
	_weapon->SetPlayer(_weaponTrans);

	_weapon2 = make_shared<Weapon>();
	_weapon2->SetPlayer(_weaponTrans2);

	_weapon3 = make_shared<Weapon>();
	_weapon3->SetPlayer(_weaponTrans3);

	_weapon4 = make_shared<Weapon>();
	_weapon4->SetPlayer(_weaponTrans4);

	_weapon5 = make_shared<Weapon>();
	_weapon5->SetPlayer(_weaponTrans5);

	
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

		w = 75.0f / 5.0f;
		h = 20.0f;
		y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/Player/player_idle_left.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/Player/player_idle_left.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/Player/player_idle_left.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/Player/player_idle_left.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/Player/player_idle_left.png"));

		}
		_actions.push_back(make_shared<Action>(clips, "B_IDLE"));
		clips.clear();

		w = 136.0f / 8.0f;
		h = 20.0f;
		y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
			clips.emplace_back(0 + w * 5, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
			clips.emplace_back(0 + w * 6, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
			clips.emplace_back(0 + w * 7, y, w, h, Texture::Add(L"Resource/Player/player_run_left.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "F_RUN"));
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
		_actions.push_back(make_shared<Action>(clips, "B_RUN"));
		clips.clear();

		w = 17.0f;
		h = 21.0f;
		y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/Player/player_jump.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "F_JUMP"));
		clips.clear();


	}


	for (auto& action : _actions)
		action->Pause();

	_actions[_aniState]->Play();

	
}

void Character::Update()
{

	switch (_aniState)
	{
	case Character::F_IDLE:
		_spriteFrontIdle->Update();
		_weapon4->Update();
		_frontIdleCollider->Update();
		break;
	case Character::B_IDLE:
		_spriteBackIdle->Update();
		_weapon5->Update();
		_backIdleCollider->Update();
		break;
	case Character::F_RUN:
		_spriteFrontRun->Update();
		_weapon->Update();
		_frontRunCollider->Update();
		break;
	case Character::B_RUN:
		_spriteBackRun->Update();
		_weapon2->Update();
		_backRunCollider->Update();
		break;
	case Character::F_JUMP:
		_spriteJump->Update();
		_weapon3->Update();
		_jumpCollider->Update();
		break;

	default:
		break;
	}

	ZeldMoveByKeyBoard();
	_jumpPower -= (float)pow(_gravity, 2) * DELTA_TIME;
	Jumping();

	_weaponTrans->UpdateWorldBuffer();
	_weaponTrans2->UpdateWorldBuffer();
	_weaponTrans3->UpdateWorldBuffer();
	_weaponTrans4->UpdateWorldBuffer();
	_weaponTrans5->UpdateWorldBuffer();

	for (auto& action : _actions)
	{
		action->Update();
		if (!action->IsPlay())
			continue;

		_spriteFrontIdle->SetClipToActionBuffer(action->GetCurClip());
		_spriteFrontRun->SetClipToActionBuffer(action->GetCurClip());
		_spriteBackIdle->SetClipToActionBuffer(action->GetCurClip());
		_spriteBackRun->SetClipToActionBuffer(action->GetCurClip());
		_spriteJump->SetClipToActionBuffer(action->GetCurClip());
	}
	
}

void Character::Render()
{
	switch (_aniState)
	{
	case Character::F_IDLE:
		_spriteFrontIdle->Render();
		_weapon4->Render();
		_frontIdleCollider->Render();
		break;
	case Character::B_IDLE:
		_spriteBackIdle->Render();
		_weapon5->Render();
		_backIdleCollider->Render();
		break;
	case Character::F_RUN:
		_spriteFrontRun->Render();
		_weapon->Render();
		_frontRunCollider->Render();
		break;
	case Character::B_RUN:
		_spriteBackRun->Render();
		_weapon2->Render();
		_backRunCollider->Render();
		break;
	case Character::F_JUMP:
		_spriteJump->Render();
		_weapon3->Render();
		_jumpCollider->Render();
		break;
	default:
		break;
	}

}

void Character::PostRender()
{
	
}

void Character::SetPostion(float x, float y)
{
	_spriteFrontIdle->GetTransform()->GetPos() = { x,y };
	_spriteFrontRun->GetTransform()->GetPos() = { x,y };
	_spriteBackIdle->GetTransform()->GetPos() = { x,y };
	_spriteBackRun->GetTransform()->GetPos() = { x,y };
	_spriteJump->GetTransform()->GetPos() = { x,y };
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

	if (KEY_PRESS('A'))
	{
		_CharacterPos.x -= 150 * DELTA_TIME;
		if (KEY_PRESS(VK_SPACE))
		{
			_isJumping = true;
			return;
		}
		this->SetAnimation(Character::State::B_RUN);
		return;
	}
	if (KEY_PRESS('D'))
	{
		_CharacterPos.x += 150 * DELTA_TIME;
		if (KEY_PRESS(VK_SPACE))
		{
			_isJumping = true;
			
			return;
		}
		this->SetAnimation(Character::State::F_RUN);
		return;
	}
	
	if (_isJumping == false)
	{
		if (KEY_PRESS(VK_SPACE))
		{
			_isJumping = true;
			return;
		}
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
	case Character::B_RUN:
		SetAnimation(State::B_IDLE);
		break;
	
	default:
		break;
	}

}

void Character::Jumping()
{      

	if (_isJumping == false)
		return;

	Vector2 temp;

	temp.y = _jumpPower;
	_CharacterPos += temp * DELTA_TIME;
	this->SetAnimation(Character::State::F_JUMP);

	for (auto& tile :_tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (tile->GetColl()->IsCollision(_jumpCollider, false))
		{
			tile->GetColl()->SetRed();
			if (_CharacterPos.y <= tile->GetColl()->Top() + _jumpCollider->GetWorldHalfY() + 30.0f)
			{
				this->SetAnimation(Character::State::F_IDLE);
				_jumpPower = 200.0f;
				_isJumping = false;
			}
		}
		else
		{
			tile->GetColl()->SetGreen();
		}
	}


	
	
}



ssWslash Character::Get_sswSlash()
{
	return slashstate;
}
