#include "framework.h"
#include "Players.h"

Players::Players(wstring file, Vector2 maxFrame, float speed)
	: _maxFrame(maxFrame)
{
	_sprite = make_shared<Sprite>(file, maxFrame);
	_col = make_shared<RectCollider>(_sprite->GetHalfFrameSize());

	_sprite->GetTransform()->GetScale() = { 2.0f,2.0f };
	_col->SetParent(_sprite->GetTransform());

	CreateAction(file, speed);
	_action->SetEndEvent(std::bind(&Players::End, this));

	_FollowTrans = make_shared<Transform>();
	_FollowTrans->GetPos() = _sprite->GetTransform()->GetPos();

	_AnginTrans = make_shared<Transform>();
	_AnginTrans->SetParent(_sprite->GetTransform());
	_AnginTrans->GetPos().x = _sprite->GetHalfSize().x;

	_Weapon = make_shared<Weapon>(L"Resource/Weapon/Boomerang_Moving.png", Vector2(2, 1), 0.5f);

	_WeaponTrans = make_shared<Transform>();
	_WeaponTrans->SetParent(_sprite->GetTransform());
	_WeaponTrans->GetPos().x = _sprite->GetHalfSize().x;

	_WeaponIdle = make_shared<Weapon>(L"Resource/Weapon/Boomerang_Moving.png", Vector2(1, 1), 0.5f);
	_WeaponIdle->SetPlayer(_WeaponTrans);
	_WeaponIdle->Play();
}

Players::~Players()
{
}

void Players::CreateAction(wstring file, float speed)
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

	size_t t = file.find(L"Player/", 0);
	string temp = WstringToString(file.substr(t + 8, file.length()));

	_action = make_shared<Action>(clips, temp.substr(0, temp.length() - 4), Action::LOOP, speed);
}

void Players::Update()
{
	if (_isActive == false)
		return;

	_WeaponIdle->Update();

	_sprite->Update();
	_action->Update();
	_col->Update();
	_sprite->SetClipToActionBuffer(_action->GetCurClip());
	_Weapon->Update();
	_WeaponIdle->Update();

	
	Aiming();
	Fire();
}

void Players::Render()
{
	if (_isActive == false)
		return;

	_WeaponIdle->Render();

	_sprite->Render();
	_col->Render();
	_Weapon->Render();
	_WeaponIdle->Render();

}

void Players::Play(Vector2 pos)
{
	_isActive = true;
	_sprite->GetTransform()->GetPos() = pos;
	_action->Play();
	_enemyPos = pos;
}



void Players::Aiming()
{
	Vector2 v = MOUSE_POS - _AnginTrans->GetWorldPos();
	float angle = v.Angle();
	_AnginTrans->GetAngle() = angle;
}

void Players::Fire()
{
	if (KEY_Down(VK_LBUTTON))
	{
		Vector2 v = MOUSE_POS - _sprite->GetTransform()->GetWorldPos();
		v.Normallize();
		_Weapon->SetDirection(v);
		_Weapon->SetPosition(_sprite->GetTransform()->GetWorldPos());
		_Weapon->Play();
	}
}
