#include "framework.h"
#include "Creature.h"

Creature::Creature()
{
	_idleEnemy = make_shared<Enemy>(L"Resource/Creature/idle.png", Vector2(12, 1), 0.1f);
	_moveEnemy = make_shared<Enemy>(L"Resource/Creature/move.png", Vector2(6, 1), 0.1f);
	_idleEnemy->Play(CENTER);
	_moveEnemy->Play(CENTER);
}

Creature::~Creature()
{
}

void Creature::Update()
{
	Move();
	switch (_aniState)
	{
	case Creature::IDLE:
		_idleEnemy->Update();
		break;
	case Creature::IDLE_SHOT:
		break;
	case Creature::ATTACK:
		break;
	case Creature::ATTACK_SHOT:
		break;
	case Creature::MOVE:
		_moveEnemy->Update();
		break;
	case Creature::MOVE_SHDT:
		break;
	default:
		break;
	}

	_runTime += DELTA_TIME;
	if (_runTime > _travelTime)
	{
		_isActive = false;
		_runTime = 0.0f;
	}

	
}

void Creature::Render()
{
	switch (_aniState)
	{
	case Creature::IDLE:
		_idleEnemy->Render();
		break;
	case Creature::IDLE_SHOT:
		break;
	case Creature::ATTACK:
		break;
	case Creature::ATTACK_SHOT:
		break;
	case Creature::MOVE:
		_moveEnemy->Render();
		break;
	case Creature::MOVE_SHDT:
		break;
	default:
		break;
	}
	
}

void Creature::PostRender()
{
	
	
}

void Creature::SetPostion(float x, float y)
{
	_idleEnemy->GetTransform()->GetPos() = { x,y };
	_moveEnemy->GetTransform()->GetPos() = { x,y };
	_creaturePos = { x,y };
}

void Creature::SetPlay(State stay)
{
	_aniState = stay;
}

void Creature::Attack(shared_ptr<class Character> character)
{
	
	
}

void Creature::Move()
{
	this->SetPostion(_creaturePos.x, _creaturePos.y);

	if (_dir == Creature::Direction::LEFT)
	{
		if (_creaturePos.x >= 550.0f)
		{
			
			_creaturePos.x -= 50.0f * DELTA_TIME;
			this->SetPlay(Creature::State::MOVE);
			return;
		}
		else 
		{
			_dir = Creature::Direction::RIGHT;
			return;
		}
	}

	if (_dir == Creature::Direction::RIGHT)
	{
		if (_creaturePos.x <= 850.0f)
		{
			_creaturePos.x += 50.0f * DELTA_TIME;
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
	case Creature::IDLE_SHOT:
		break;
	case Creature::ATTACK:
		break;
	case Creature::ATTACK_SHOT:
		break;
	case Creature::MOVE:
		SetPlay(State::IDLE);
		break;
	case Creature::MOVE_SHDT:
		break;
	default:
		break;
	}
}

void Creature::SetTravel(Vector2 tra)
{
	_travel = tra;
}
