#include "framework.h"
#include "Creature.h"

Creature::Creature()
{
	_idleEnemy = make_shared<Enemy>(L"Resource/Creature/idle.png", Vector2(12, 1), 0.1f);
	_moveEnemy = make_shared<Enemy>(L"Resource/Creature/move.png", Vector2(6, 1), 0.1f);

	_leftIdleEnemy = make_shared<Enemy>(L"Resource/Creature/leftidle.png", Vector2(12, 1), 0.1f);
	_leftMoveEnemy = make_shared<Enemy>(L"Resource/Creature/leftmove.png", Vector2(6, 1), 0.1f);

	_attack = make_shared<Enemy>(L"Resource/Creature/attack.png", Vector2(1, 1), 0.1f);

	_idleEnemy->Play(CENTER);
	_moveEnemy->Play(CENTER);

	_leftIdleEnemy->Play(CENTER);
	_leftMoveEnemy->Play(CENTER);

	_attack->Play(CENTER);

	_dir = Creature::Direction::LEFT;
	_isActive = true;
}

Creature::~Creature()
{
}

void Creature::Update()
{

	if (_isActive == false)
		return;
	Move(_players->GetPlayerPos());
	

	switch (_aniState)
	{
	case Creature::IDLE:
		_idleEnemy->Update();
		break;
	case Creature::LEFTIDLE:
		_leftIdleEnemy->Update();
		break;
	case Creature::ATTACK:
		_attack->Update();
		break;
	case Creature::MOVE:
		_moveEnemy->Update();
		break;

	case Creature::LEFTMOVE:
		_leftMoveEnemy->Update();
		break;
	default:
		break;
	}
}

void Creature::Render()
{

	if (_isActive == false)
		return;
	switch (_aniState)
	{
	case Creature::IDLE:
		_idleEnemy->Render();
		break;
	case Creature::LEFTIDLE:
		_leftIdleEnemy->Render();
		break;
	case Creature::ATTACK:
		_attack->Render();
		break;
	case Creature::MOVE:
		_moveEnemy->Render();
		break;
	case Creature::LEFTMOVE:
		_leftMoveEnemy->Render();
		break;
	default:
		break;
	}

	ImGui::Text("Target hp: %d", (UINT)_hp);
	
}

void Creature::PostRender()
{
	
	
}

void Creature::SetPostion(float x, float y)
{
	_idleEnemy->GetTransform()->GetPos() = { x,y };
	_moveEnemy->GetTransform()->GetPos() = { x,y };
	_leftIdleEnemy->GetTransform()->GetPos() = { x,y };
	_leftMoveEnemy->GetTransform()->GetPos() = { x,y };
	_attack->GetTransform()->GetPos() = { x,y };
	_creaturePos = { x,y };
}

void Creature::SetPlay(State stay)
{
	_aniState = stay;
}


void Creature::Move(Vector2 pos)
{
	this->SetPostion(_creaturePos.x, _creaturePos.y);

	if ((pos - _creaturePos).Length() < 10.0f)
		return;

	
	Vector2 vector = (pos - _creaturePos);
	vector.Normallize();

	

	if (_dir == Creature::Direction::LEFT)
	{
		if (_creaturePos.x >=_players->GetPlayerPos().x)
		{
			_creaturePos.x += vector.x * DELTA_TIME * _speed;
			_creaturePos.y += vector.y * DELTA_TIME * _speed;
			this->SetPlay(Creature::State::LEFTMOVE);
			return;
		}else
		{
			_dir = Creature::Direction::RIGHT;
			return;
		}
	}
	
	if (_dir == Creature::Direction::RIGHT)
	{
	
		if (_creaturePos.x <= _players-> GetPlayerPos().x)
		{
			_creaturePos.x += vector.x * DELTA_TIME * _speed;
			_creaturePos.y += vector.y * DELTA_TIME * _speed;
			this->SetPlay(Creature::State::MOVE);
			return;
		}
		else
		{
			_dir = Creature::Direction::LEFT;
			return;
		}
	}
	
	SEltDLE();

}

void Creature::SEltDLE()
{
	switch (_aniState)
	{
	case Creature::ATTACK:
		SetPlay(State::IDLE);
		break;
	case Creature::MOVE:
		SetPlay(State::IDLE);
		break;
	case Creature::LEFTMOVE:
		SetPlay(State::LEFTIDLE);
		break;
	default:
		break;
	}

}

void Creature::AttackPlayer(shared_ptr<class TestPlayer> player)
{
	if (player->_isActive == false || _moveEnemy->_isActive== false)
	{
		return;
	}
	this->SetPostion(_creaturePos.x, _creaturePos.y);

	if (player->GetCol1()->IsCollision(_moveEnemy->GetColl()))
	{
		this->SetPlay(Creature::State::ATTACK);
		if (player->GetCol1()->IsCollision(_attack->GetColl()))
		{
			player->GetCol1()->SetRed();
			player->_hp -= _Damage;
		}
	}
	else
	{
		player->GetCol1()->SetGreen();
	}


	
}

void Creature::SetTravel(Vector2 tra)
{
	_travel = tra;
}



