#include "framework.h"
#include "Players.h"

Players::Players(wstring file, Vector2 maxFrame, float speed)
	: _maxFrame(maxFrame)
{
	
	_sprite = make_shared<Sprite>(file, maxFrame);
	_col = make_shared<RectCollider>(_sprite->GetHalfFrameSize());
	_eventCol = make_shared<RectCollider>(Vector2(5, 2));
	_eventCol->GetLocalPosition() = Vector2(0.0f, -8.0f);

	_sprite->GetTransform()->GetScale() = { 2.0f,2.0f };
	_col->SetParent(_sprite->GetTransform());
	_eventCol->SetParent(_sprite->GetTransform());

	CreateAction(file, speed);
	_action->SetEndEvent(std::bind(&Players::End, this));


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

	
	_sprite->Update();
	_action->Update();
	_sprite->SetClipToActionBuffer(_action->GetCurClip());
	_col->Update();
	_eventCol->Update();

}

void Players::Render()
{
	if (_isActive == false)
		return;
	_sprite->Render();
	_col->Render();
	_eventCol->Render();
	
}

void Players::Play(Vector2 pos)
{
	_isActive = true;
	_sprite->GetTransform()->GetPos() = pos;
	_action->Play();
	_enemyPos = pos;
}



