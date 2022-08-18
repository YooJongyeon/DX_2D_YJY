#include "framework.h"
#include "SceneManager.h"

#include "../Scene/BagicScene/TextureScene.h"
#include "../Scene/BagicScene/TextureWVPScene.h"
#include "../Scene/BagicScene/SolarSystemScene.h"
#include "../Scene/BagicScene/DungreedScene.h"
#include "../Scene/BagicScene/ColliderScene.h"
#include "../Scene/BagicScene/ZeldaScene.h"
#include "../Scene//BagicScene/FillterScene.h"
#include "../Scene/BagicScene/EffectScene.h"
#include "../Scene/BagicScene/CameraScene.h"
#include "../Scene/TestScene.h"
#include "../Scene/BagicScene/XmlLoadScene.h"
#include "../Scene/BagicScene/InstancingScene.h"

SceneManager* SceneManager::_instance = nullptr;

SceneManager::SceneManager()
{
	_sceneTable["Test"] = make_shared<TestScene>();
	_sceneTable["Dungreed"] = make_shared<DungreedScene>();
	_sceneTable["Texture"] = make_shared<TextureScene>();

	_curScene = _sceneTable["Test"];
}

SceneManager::~SceneManager()
{
}

void SceneManager::Update()
{
	if (!_curScene.expired())
		_curScene.lock()->Update();
}

void SceneManager::Render()
{
	if (!_curScene.expired())
		_curScene.lock()->Render();
}

void SceneManager::PreRender()
{
	if (!_curScene.expired())
		_curScene.lock()->PreRender();
}

void SceneManager::PostRender()
{
	if (!_curScene.expired())
		_curScene.lock()->PostRender();
}

void SceneManager::SetScene(string name)
{
	if (_sceneTable.count(name) == 0)
		return;

	_curScene = _sceneTable[name];
	_curScene.lock()->Init();
}
