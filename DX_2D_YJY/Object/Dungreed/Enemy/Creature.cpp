#include "framework.h"
#include "Creature.h"

Creature::Creature()
{
	/*_Idle = make_shared<Sprite>(L"Resource/Boss/Belial/Head/idle.png", Vector2(9, 1)); 
	_Idle->GetTransform()->GetScale() = { 2.0f, 2.0f };
	_Idle->GetTransform()->GetPos() = Vector2(WIN_WIDTH * 0.3f, WIN_HEIGHT * 0.5f);*/

	//ObjectMananger::GetInstance()->Add(L"Resource/Boss/Belial/Head/attack.png", Vector2(10, 1), 0.07f);

	//ObjectMananger::GetInstance()->Add(L"Resource/Creature/idle.png", Vector2(12, 1), 0.07f);
	//CreateActions();
}

Creature::~Creature()
{
}

void Creature::CreateActions()
{
	_actions.reserve(9);
	{
		vector<Action::Clip> clips;

		float w = 700.0f/10.0f ;
		float h = 96.0f;
		float y = 0;
		{
			clips.emplace_back(0, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w * 2, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w * 3, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w * 4, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w * 5, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w * 6, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w * 7, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
			clips.emplace_back(0 + w * 8, y, w, h, Texture::Add(L"Resource/Boss/Belial/Head/idle.png"));
		}
		_actions.push_back(make_shared<Action>(clips, "IDLE"));
		clips.clear();

	}

	for (auto& action : _actions)
		action->Pause();

	_actions[_aniState]->Play();


}


void Creature::Update()
{
	/*switch (_aniState)
	{
	case Creature::IDLE:
		_Idle->Update();
		break;
	case Creature::IDLE_SHOT:
		break;
	default:
		break;
	}*/

	if (KEY_Down(VK_F2))
	{
		ObjectMananger::GetInstance()->Play("idle", CENTER);
		//Camera::GetInstance()->ShakeStart(10.0f, 1.0f);
	}

;
	//
	//for (auto& action :_actions)
	//{
	//	action->Update();
	//	if (!action->IsPlay())
	//		continue;

	//	_Idle->SetClipToActionBuffer(action->GetCurClip());

	//}

	
}

void Creature::Render()
{
	//switch (_aniState)
	//{
	//case Creature::IDLE:
	//	_Idle->Render();
	//	break;
	//case Creature::IDLE_SHOT:
	//	break;
	//default:
	//	break;
	//}

	
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
	//if (_actions[aniState]->IsPlay() && _actions[aniState]->GetAnimType() == Action::LOOP)
	//	return;

	//for (auto& action : _actions)
	//{
	//	if (action->IsPlay() && _aniState == aniState)
	//		continue;

	//	action->Reset();
	//}

	//_actions[aniState]->Play();
	//_aniState = aniState;
}

void Creature::Attack(shared_ptr<class Character> character)
{

}
