#include "framework.h"
#include "TestPlayer.h"

TestPlayer::TestPlayer()
{
	_FidleEnemy = make_shared<Players>(L"Resource/Player/player_idle.png", Vector2(5, 1), 0.1f);
	_FmoveEnemy = make_shared<Players>(L"Resource/Player/player_run.png", Vector2(8, 1), 0.1f);

	_BidleEnemy = make_shared<Players>(L"Resource/Player/player_idle_left.png", Vector2(5, 1), 0.1f);
	_BmoveEnemy = make_shared<Players>(L"Resource/Player/player_run_left.png", Vector2(8, 1), 0.1f);

	_FjumpEnemy = make_shared<Players>(L"Resource/Player/player_jump.png", Vector2(1, 1), 0.1f);
	_BjumpEnemy = make_shared<Players>(L"Resource/Player/player_Backjump.png", Vector2(1, 1), 0.1f);

	_FidleEnemy->Play(Vector2(0.0f, 0.0f));
	_FmoveEnemy->Play(Vector2(0.0f, 0.0f));

	_BidleEnemy->Play(Vector2(0.0f, 0.0f));
	_BmoveEnemy->Play(Vector2(0.0f, 0.0f));

	_FjumpEnemy->Play(Vector2(0.0f, 0.0f));
	_BjumpEnemy->Play(Vector2(0.0f, 0.0f));

	_quad = make_shared <Quad>(L"Resource/adventure.png");
	_quad->GetTransform()->GetScale() = { 0.9f, 0.9f };
	_quad->SetParent(_FmoveEnemy->GetTransform());

	_Weapon = make_shared<Weapon>(L"Resource/Weapon/TigerPunch.png", Vector2(10, 1), 0.07f);

	SOUND->Add("TigerToar","Resource/Sound/TigerRoar.wav");
	SOUND->Add("jumping","Resource/Sound/Jumping.wav");
	_isfal = true;
	_isActive = true;
}

TestPlayer::~TestPlayer()
{
}

void TestPlayer::Update()
{
	if (_isActive == false)
		return;

	
	switch (_aniState)
	{
	case TestPlayer::F_IDLE:
		_FidleEnemy->Update();
		break;
	case TestPlayer::B_IDLE:
		_BidleEnemy->Update();
		break;
	case TestPlayer::F_RUN:
		_FmoveEnemy->Update();
		break;
	case TestPlayer::B_RUN:
		_BmoveEnemy->Update();
		break;
	case TestPlayer::F_JUMP:
		_FjumpEnemy->Update();
		break;
	case TestPlayer::B_JUMP:
		_BjumpEnemy->Update();
		break;
	default:
		break;
	}
	_quad->Update();
	
	_Weapon->Update();

	if (MOUSE_WORLDPOS.x <= (_quad->Left()))
		_aniState = B_IDLE;
	else if (MOUSE_WORLDPOS.x >= (_quad->Left()))
		_aniState = F_IDLE;

	Move();
	Gravity();
	BackGravity();
	FRunGravity();
	BRunGravity();
	Jumping();
	BackJumping();
	Fire();




	
}

void TestPlayer::Render()
{
	if (_isActive == false)
		return;

	switch (_aniState)
	{
	case TestPlayer::F_IDLE:
		_FidleEnemy->Render();
		break;
	case TestPlayer::B_IDLE:
		_BidleEnemy->Render();
		break;
	case TestPlayer::F_RUN:
		_FmoveEnemy->Render();
		break;
	case TestPlayer::B_RUN:
		_BmoveEnemy->Render();
		break;
	case TestPlayer::F_JUMP:
		_FjumpEnemy->Render();
		break;
	case TestPlayer::B_JUMP:
		_BjumpEnemy->Render();
		break;
	default:
		break;
	}
	_Weapon->Render();

	ImGui::Text("Target hp: %d", (UINT)_hp);

}

void TestPlayer::PostRender()
{
}

void TestPlayer::SetPostion(float x, float y)
{
	_FidleEnemy->GetTransform()->GetPos() = { x,y };
	_FmoveEnemy->GetTransform()->GetPos() = { x,y };
	_BidleEnemy->GetTransform()->GetPos() = { x,y };
	_BmoveEnemy->GetTransform()->GetPos() = { x,y };
	_FjumpEnemy->GetTransform()->GetPos() = { x,y };
	_BjumpEnemy->GetTransform()->GetPos() = { x,y };
	_PlayerPos = { x,y };
}

void TestPlayer::SetPlay(State stay)
{
	_aniState = stay;
}


void TestPlayer::Move()
{
	this->SetPostion(_PlayerPos.x, _PlayerPos.y);
	
	
	if (KEY_PRESS('A'))
	{
		_PlayerPos.x -= 150 * DELTA_TIME;
		if (KEY_PRESS(VK_SPACE))
		{
			_isBackJumping = true;
			SOUND->Play("jumping", 0.5f);
		
			return;
		}
		this->SetPlay(TestPlayer::State::B_RUN);

		return;
	}

	if (KEY_PRESS('D'))
	{
		_PlayerPos.x += 150 * DELTA_TIME;
		if (KEY_PRESS(VK_SPACE))
		{
			_isJumping = true;
			SOUND->Play("jumping", 0.1f);
			return;
		}
	
		this->SetPlay(TestPlayer::State::F_RUN);

		return;
	}

	if (_aniState == TestPlayer::State::B_IDLE)
	{
		if (_isBackJumping == false)
		{
			if (KEY_PRESS(VK_SPACE))
			{
				_isBackJumping = true;
				SOUND->Play("jumping", 0.5f);

				return;
			}
		}
	}
	if (_aniState == TestPlayer::State::F_IDLE)
	{
		if (_isJumping == false)
		{
			if (KEY_PRESS(VK_SPACE))
			{
				_isJumping = true;
				SOUND->Play("jumping", 0.5f);
				return;
			}
		}
	}

	SEltDLE();
}

void TestPlayer::SEltDLE()
{
	switch (_aniState)
	{
	case TestPlayer::F_RUN:
		SetPlay(State::F_IDLE);
		break;
	case TestPlayer::B_RUN:
		SetPlay(State::B_IDLE);
		break;
	default:
		break;
	}
}

void TestPlayer::Jumping()
{
	if (_isJumping == false)
		return;
	this->SetPostion(_PlayerPos.x, _PlayerPos.y);

	Vector2 temp;
	_jumpPower -= (float)pow(_gravity, 2);
	temp.y = _jumpPower;
	_PlayerPos += temp * DELTA_TIME;
	this->SetPlay(TestPlayer::State::F_JUMP);

	for (auto& tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (_jumpPower >=0.0f)
		{
			break;
		}
		if (tile->GetColl()->IsCollision(_FjumpEnemy->GetTileEventColl()))
		{
			tile->GetColl()->SetRed();
			
			if (_PlayerPos.y <= tile->GetColl()->Top() + _FjumpEnemy->GetTileEventColl()->Bottom() + 10.0f)
			{
				
				this->SetPlay(TestPlayer::State::F_IDLE);
				_isJumping = false;
				_jumpPower = 500.0f;
			}
		}
		else
		{
			tile->GetColl()->SetGreen();
		}
	}

}

void TestPlayer::BackJumping()
{
	if (_isBackJumping == false)
		return;
	this->SetPostion(_PlayerPos.x, _PlayerPos.y);

	Vector2 temp;
	_BackjumpPower -= (float)pow(_gravity, 2);
	temp.y = _BackjumpPower;
	_PlayerPos += temp * DELTA_TIME;
	this->SetPlay(TestPlayer::State::B_JUMP);

	for (auto& tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (_BackjumpPower >= 0.0f)
		{
			break;
		}
		if (tile->GetColl()->IsCollision(_BjumpEnemy->GetTileEventColl()))
		{
			tile->GetColl()->SetRed();

			if (_PlayerPos.y <= tile->GetColl()->Top() + _BjumpEnemy->GetTileEventColl()->Bottom() + 10.0f)
			{
				this->SetPlay(TestPlayer::State::B_IDLE);
				_isBackJumping = false;
				_BackjumpPower = 500.0f;
			}

		}
		else
		{
			tile->GetColl()->SetGreen();
		}
	}
}

void TestPlayer::Gravity()
{
	if (_isfal == false)
		return;
	this->SetPostion(_PlayerPos.x, _PlayerPos.y);

	if (_aniState == TestPlayer::State::F_IDLE)
	{

		if (_isfal == true)
		{
			Vector2 temp;
			_fGravutyPower -= (float)pow(_fGravity, 2);
			temp.y = _fGravutyPower;
			_PlayerPos += temp * DELTA_TIME;
		}

	}
	
	for (auto& tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (_fGravutyPower >= 0.0f)
		{
			break;
		}
		if (tile->GetColl()->IsCollision(_FidleEnemy->GetTileEventColl()))
		{
			tile->GetColl()->SetRed();
			if (_PlayerPos.y <= tile->GetColl()->Top() + _FidleEnemy->GetTileEventColl()->Bottom() + 10.0f)
			{
				
				_fGravutyPower = 2.0f;
			}
		}
		else
		{
			tile->GetColl()->SetGreen();
			_isfal = true;
		}
	}
}

void TestPlayer::BackGravity()
{
	if (_backIsfal == false)
		return;

	this->SetPostion(_PlayerPos.x, _PlayerPos.y);
	if (_aniState == TestPlayer::State::B_IDLE)
	{
		if (_backIsfal == true)
		{
			Vector2 temp;
			_bGravutyPower -= (float)pow(_bGravity, 2);
			temp.y = _bGravutyPower;
			_PlayerPos += temp * DELTA_TIME;
		}
	}

	for (auto& tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (_bGravutyPower >= 0.0f)
		{
			break;
		}
		if (tile->GetColl()->IsCollision(_BidleEnemy->GetTileEventColl()))
		{
			tile->GetColl()->SetRed();
			if (_PlayerPos.y <= tile->GetColl()->Top() + _BidleEnemy->GetTileEventColl()->Bottom() + 10.0f)
			{
				
				_bGravutyPower = 2.0f;
			}
		}
		else
		{
			tile->GetColl()->SetGreen();
			_backIsfal = true;
		}
	}
}

void TestPlayer::FRunGravity()
{
	if (_FRunIsfal == false)
		return;

	this->SetPostion(_PlayerPos.x, _PlayerPos.y);
	if (_aniState == TestPlayer::State::F_RUN)
	{
		if (_FRunIsfal == true)
		{
			Vector2 temp;
			_fRunGravutyPower -= (float)pow(_fRunGravity, 2);
			temp.y = _fRunGravutyPower;
			_PlayerPos += temp * DELTA_TIME;
		}
	}

	for (auto& tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (_fRunGravutyPower >= 0.0f)
		{
			break;
		}
		if (tile->GetColl()->IsCollision(_FmoveEnemy->GetTileEventColl()))
		{
			tile->GetColl()->SetRed();
			if (_PlayerPos.y <= tile->GetColl()->Top() + _FmoveEnemy->GetTileEventColl()->Bottom() + 10.0f)
			{
				
				_fRunGravutyPower = 2.0f;
			}
		}
		else
		{
			tile->GetColl()->SetGreen();
			_FRunIsfal = true;
		}
	}
}

void TestPlayer::BRunGravity()
{
	if (_BRunIsfal == false)
		return;

	this->SetPostion(_PlayerPos.x, _PlayerPos.y);
	if (_aniState == TestPlayer::State::B_RUN)
	{
		if (_BRunIsfal == true)
		{
			Vector2 temp;
			_bRuneGravutyPower -= (float)pow(_bRunbGravity, 2);
			temp.y = _bRuneGravutyPower;
			_PlayerPos += temp * DELTA_TIME;
		}
	}

	for (auto& tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (_bRuneGravutyPower >= 0.0f)
		{
			break;
		}
		if (tile->GetColl()->IsCollision(_BmoveEnemy->GetTileEventColl()))
		{
			tile->GetColl()->SetRed();
			if (_PlayerPos.y <= tile->GetColl()->Top() + _BmoveEnemy->GetTileEventColl()->Bottom() + 20.0f)
			{
				
				_bRuneGravutyPower = 2.0f;
			}
		}
		else
		{
			tile->GetColl()->SetGreen();
			_BRunIsfal = true;
		}
	}
}

void TestPlayer::Fire()
{
	if (KEY_Down(VK_LBUTTON))
	{
		Vector2 v = MOUSE_WORLDPOS;
		_Weapon->SetPosition(v);
		SOUND->Play("TigerToar", 0.5f);
		_Weapon->Play();
	}
}

void TestPlayer::AttackMonsters(shared_ptr<class Creature> Enemy)
{
	if (!_Weapon->_isActive)
		return;
	
	if (Enemy->GetCol1()->IsCollision(_Weapon->GetColl()))
	{
		Enemy->GetCol1()->SetRed();
		Enemy->_hp -= _weaponDamage;
	}
	else
	{
		Enemy->GetCol1()->SetGreen();
	}


	if (Enemy->GetCol2()->IsCollision(_Weapon->GetColl()))
	{
		Enemy->GetCol2()->SetRed();
		Enemy->_hp -= _weaponDamage;
	}
	else
	{
		Enemy->GetCol2()->SetGreen();
	}

	
}

void TestPlayer::AttackGhost(shared_ptr<class Ghost> Ghost)
{

	if (!_Weapon->_isActive)
		return;

	if (Ghost->GetCol1()->IsCollision(_Weapon->GetColl()))
	{
		Ghost->GetCol1()->SetRed();
		Ghost->_hp -= _weaponDamage;
	}
	else
	{
		Ghost->GetCol1()->SetGreen();
	}


	if (Ghost->GetCol2()->IsCollision(_Weapon->GetColl()))
	{
		Ghost->GetCol2()->SetRed();
		Ghost->_hp -= _weaponDamage;
	}
	else
	{
		Ghost->GetCol2()->SetGreen();
	}

}

