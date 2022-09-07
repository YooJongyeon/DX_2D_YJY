#include "framework.h"
#include "Ghost.h"

Ghost::Ghost()
{
	_moveEnemy = make_shared<Enemy>(L"Resource/Creature/Ghostmove.png", Vector2(6, 1), 0.1f);
	_leftMoveEnemy = make_shared<Enemy>(L"Resource/Creature/GhostTwistMove.png", Vector2(6, 1), 0.1f);

	_attack = make_shared<Enemy>(L"Resource/Creature/Ghostattack.png", Vector2(3, 1), 0.1f);
	
	_moveEnemy->Play(Vector2(1200, 300));
	_leftMoveEnemy->Play(Vector2(1200, 300));
	_attack->Play(Vector2(1200, 300));

	_dir = Ghost::Direction::LEFT;
	_isActive = true;
}

Ghost::~Ghost()
{
}

void Ghost::Update()
{
	if (_isActive == false)
		return;
	Move(_players->GetPlayerPos());


	switch (_aniState)
	{
	case Ghost::MOVE:
		_moveEnemy->Update();
		break;

	case Ghost::LEFTMOVE:
		_leftMoveEnemy->Update();
		break;
	case Ghost::ATTACK:
		_attack->Update();
		break;
	default:
		break;
	}
}

void Ghost::Render()
{
	if (_isActive == false)
		return;
	switch (_aniState)
	{
	case Ghost::MOVE:
		_moveEnemy->Render();
		break;

	case Ghost::LEFTMOVE:
		_leftMoveEnemy->Render();
		break;
	case Ghost::ATTACK:
		_attack->Render();
		break;
	default:
		break;
	}
}

void Ghost::PostRender()
{
}

void Ghost::SetPostion(Vector2 x, Vector2 y)
{
	_moveEnemy->GetTransform()->GetPos() = ( x,y) ;
	_leftMoveEnemy->GetTransform()->GetPos() = (x, y);
	_attack->GetTransform()->GetPos() = (x, y);
	_creaturePos = (x, y);
}

void Ghost::SetPlay(State stay)
{
	_aniState = stay;
}

void Ghost::Move(Vector2 pos)
{
	this->SetPostion(_creaturePos, _creaturePos);

	if ((pos - _creaturePos).Length() < 10.0f)
		return;


	Vector2 vector = (pos - _creaturePos);
	vector.Normallize();



	if (_dir == Ghost::Direction::LEFT)
	{
		if (_creaturePos.x >= _players->GetPlayerPos().x)
		{
			_creaturePos.x += vector.x * DELTA_TIME * _speed;
			_creaturePos.y += vector.y * DELTA_TIME * _speed;
			this->SetPlay(Ghost::State::LEFTMOVE);
			return;
		}
		else
		{
			_dir = Ghost::Direction::RIGHT;
			return;
		}
	}

	if (_dir == Ghost::Direction::RIGHT)
	{

		if (_creaturePos.x <= _players->GetPlayerPos().x)
		{
			_creaturePos.x += vector.x * DELTA_TIME * _speed;
			_creaturePos.y += vector.y * DELTA_TIME * _speed;
			this->SetPlay(Ghost::State::MOVE);
			return;
		}
		else
		{
			_dir = Ghost::Direction::LEFT;
			return;
		}
	}

	
}

void Ghost::AttackPlayer(shared_ptr<class TestPlayer> player)
{
	if (player->_isActive == false || _moveEnemy->_isActive == false)
	{
		return;
	}
	this->SetPostion(_creaturePos, _creaturePos);

	if (player->GetFidleColl()->IsCollision(_moveEnemy->GetColl()))
	{
		player->GetFidleColl()->SetRed();
		this->SetPlay(Ghost::State::ATTACK);
		if (player->GetFidleColl()->IsCollision(_attack->GetColl()))
		{
			player->_hp -= _Damage;
		}
	}
	else
	{
		player->GetFidleColl()->SetGreen();
	}

	if (player->GetFidleColl()->IsCollision(_leftMoveEnemy->GetColl()))
	{
		player->GetFidleColl()->SetRed();
		this->SetPlay(Ghost::State::ATTACK);
		if (player->GetFidleColl()->IsCollision(_attack->GetColl()))
		{
			player->_hp -= _Damage;
		}
	}
	else
	{
		player->GetFidleColl()->SetGreen();
	}
}
