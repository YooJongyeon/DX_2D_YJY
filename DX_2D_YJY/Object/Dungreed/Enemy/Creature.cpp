#include "framework.h"
#include "Creature.h"

Creature::Creature()
{
	EnemyManager::GetInstance()->Add(L"Resource/Creature/idle.png", Vector2(12, 1), 0.07f);
	EnemyManager::GetInstance()->Add(L"Resource/Creature/move.png", Vector2(6, 1), 0.07f);
	
	CreateActions();
}

Creature::~Creature()
{
}

void Creature::CreateActions()
{
	
	
}


void Creature::Update()
{
	switch (_aniState)
	{
	case Creature::IDLE:
		EnemyManager::GetInstance()->Play("idle", Vector2(300, 100));
		break;
	case Creature::ATTACK:
		EnemyManager::GetInstance()->Play("move", Vector2(300, 100));
		break;
	default:
		break;
	}
	
}

void Creature::Render()
{
	
	
}

void Creature::PostRender()
{
}

void Creature::SetPostion(float x, float y)
{
	_Idle->GetTransform()->GetPos() = { x,y };
	_Attack->GetTransform()->GetPos() = { x,y };
}

void Creature::SetAnimation(HeadState aniState)
{
	
	EnemyManager::GetInstance()->Play("move", Vector2(300, 100));
}

void Creature::Attack(shared_ptr<class Character> character)
{
	
	
}

void Creature::Move()
{
	
}
