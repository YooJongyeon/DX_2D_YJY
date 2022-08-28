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
	Move(_players->GetPlayerPos());
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


void Creature::Move(Vector2 pos)
{
	this->SetPostion(_creaturePos.x, _creaturePos.y);

	if ((pos - _creaturePos).Length() < 10.0f)
		return;

	Vector2 vector = (pos - _creaturePos);
	vector.Normallize();

	if (_creaturePos.x == _players->GetPlayerPos().x || _creaturePos.y == _players->GetPlayerPos().y)
	{
		_dir = Creature::Direction::LEFT;
	}

	if (_dir == Creature::Direction::LEFT)
	{
		if (_creaturePos.x >= _players->GetPlayerPos().x)
		{
			_creaturePos.x += vector.x * DELTA_TIME * _speed;
			_creaturePos.y += vector.y * DELTA_TIME * _speed;
			this->SetPlay(Creature::State::MOVE);
			return;
		}else
		{
			_dir = Creature::Direction::RIGHT;
			return;
		}
	}
	
	if (_dir == Creature::Direction::RIGHT)
	{
		if (_creaturePos.x <= _players->GetPlayerPos().x)
		{
			_creaturePos.x += vector.x * DELTA_TIME * _speed;
			_creaturePos.y += vector.y * DELTA_TIME * _speed;
			this->SetPlay(Creature::State::IDLE);
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
