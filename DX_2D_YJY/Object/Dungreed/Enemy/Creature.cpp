#include "framework.h"
#include "Creature.h"

Creature::Creature()
{
	_idleEnemy = make_shared<Enemy>(L"Resource/Creature/idle.png", Vector2(12, 1), 0.07f);
	_idleEnemy->Play(CENTER);
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
		break;
	case Creature::MOVE_SHDT:
		break;
	default:
		break;
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

void Creature::Attack(shared_ptr<class Character> character)
{
	
	
}

void Creature::Move()
{
	
}
