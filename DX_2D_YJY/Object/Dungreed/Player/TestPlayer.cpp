#include "framework.h"
#include "TestPlayer.h"

TestPlayer::TestPlayer()
{
	_FidleEnemy = make_shared<Players>(L"Resource/Player/player_idle.png", Vector2(5, 1), 0.1f);
	_FmoveEnemy = make_shared<Players>(L"Resource/Player/player_run.png", Vector2(8, 1), 0.1f);

	_BidleEnemy = make_shared<Players>(L"Resource/Player/player_idle_left.png", Vector2(5, 1), 0.1f);
	_BmoveEnemy = make_shared<Players>(L"Resource/Player/player_run_left.png", Vector2(8, 1), 0.1f);

	_FjumpEnemy = make_shared<Players>(L"Resource/Player/player_jump.png", Vector2(1, 1), 0.1f);

	_FidleEnemy->Play(CENTER);
	_FmoveEnemy->Play(CENTER);

	_BidleEnemy->Play(CENTER);
	_BmoveEnemy->Play(CENTER);

	_FjumpEnemy->Play(CENTER);

	_Weapon = make_shared<Weapon>(L"Resource/Weapon/TigerPunch.png", Vector2(10, 1), 0.07f);

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
	
	default:
		break;
	}

	_Weapon->Update();

	_jumpPower -= (float)pow(_gravity, 2) * DELTA_TIME;
	Move();
	Jumping();
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
			_isJumping = true;

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

			return;
		}
		this->SetPlay(TestPlayer::State::F_RUN);

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

	Vector2 temp;

	temp.y = _jumpPower;
	_PlayerPos += temp * DELTA_TIME;
	this->SetPlay(TestPlayer::State::F_JUMP);

	for (auto& tile : _tile)
	{
		if (tile->_isActive == false)
		{
			continue;
		}
		if (tile->GetColl()->IsCollision(_FjumpEnemy->GetColl(), false))
		{
			tile->GetColl()->SetRed();
			if (_PlayerPos.y <=  (tile->GetColl()->Top()) + _FjumpEnemy->GetColl()->GetWorldHalfY() + 30.0f)
			{
				this->SetPlay(TestPlayer::State::F_IDLE);
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


void TestPlayer::Fire()
{
	if (KEY_Down(VK_LBUTTON))
	{
		Vector2 v = MOUSE_POS;
		_Weapon->SetPosition(v);
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

