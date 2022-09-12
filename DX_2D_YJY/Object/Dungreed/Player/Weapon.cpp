#include "framework.h"
#include "Weapon.h"

Weapon::Weapon(wstring file, Vector2 maxFrame, float speed)
	: _maxFrame(maxFrame)
{
	_sprite = make_shared<Sprite>(file, maxFrame);
	_col = make_shared<RectCollider>(_sprite->GetHalfFrameSize());

	_sprite->GetTransform()->GetScale() = { 1.5f,1.5f };
	_col->SetParent(_sprite->GetTransform());

	CreateAction(file, speed);
	_action->SetEndEvent(std::bind(&Weapon::End, this));
}

Weapon::~Weapon()
{
}

void Weapon::CreateAction(wstring file, float speed)
{
	vector<Action::Clip> clips;
	float w = _sprite->GetHalfFrameSize().x * 2;
	float h = _sprite->GetHalfFrameSize().y * 2;

	for (int y = 0; y < _maxFrame.y; y++)
	{
		for (int x = 0; x < _maxFrame.x; x++)
		{
			clips.emplace_back(x * w, y * h, w, h, Texture::Add(file));
		}
	}

	size_t t = file.find(L"Weapon/", 0);
	string temp = WstringToString(file.substr(t + 8, file.length()));

	_action = make_shared<Action>(clips, temp.substr(0, temp.length() - 4), Action::END, speed);
}

void Weapon::Update()
{
	if (_isActive == false)
		return;

	_sprite->GetTransform()->GetPos() += _enemyPos * 100.0f * DELTA_TIME;
	_sprite->Update();
	_action->Update();
	_col->Update();
	_sprite->SetClipToActionBuffer(_action->GetCurClip());

	_sprite->GetTransform()->GetPos() += _enemyPos * 100.0f * DELTA_TIME;

	_runTime += DELTA_TIME;
	if (_runTime > _destroyTime)
	{
		_isActive = false;
		_runTime = 0.0f;
	}
}

void Weapon::Render()
{
	if (_isActive == false)
		return;

	_sprite->Render();
	//_col->Render();
}

void Weapon::Play()
{
	_isActive = true;

	_action->Play();
	
}

void Weapon::SetDirection(Vector2 dir)
{
	_enemyPos = dir;
	_sprite->GetTransform()->GetAngle() = dir.Angle();
}

bool Weapon::IsCollision(shared_ptr<class Enemy> enemy)
{
	if (enemy->_isActive == false && _isActive == false)
		return false;
	if (_col->IsCollision(enemy->GetColl()))
	{
		return true;
	}
	return false;
}



