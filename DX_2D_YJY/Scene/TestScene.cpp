#include "framework.h"
#include "TestScene.h"

TestScene::TestScene()
{
	_character = make_shared<Character>();
}

TestScene::~TestScene()
{
}

void TestScene::Update()
{
	_character->Update();
	
}

void TestScene::Render()
{
	_character->Render();
}

void TestScene::PostRender()
{
	
}
