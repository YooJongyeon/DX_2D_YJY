#include "framework.h"
#include "Creature.h"

Creature::Creature()
{
	_idleEnemy = make_shared<Enemy>(L"Resource/Creature/idle.png", Vector2(12, 1), 0.07f);
	_moveEnemy = make_shared<Enemy>(L"Resource/Creature/move.png", Vector2(6, 1), 0.07f);
	_idleEnemy->Play(CENTER);
	_moveEnemy->Play(CENTER);
}

Creature::~Creature()
{
}

void Creature::Update()
{
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
	
	Move();
	
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

	if (KEY_PRESS('L'))
	{
		_creaturePos.x -= 150 * DELTA_TIME;
		this->SetPlay(Creature::State::MOVE);

		return;
	}

}
