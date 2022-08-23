#include "framework.h"
#include "ItemScene.h"

ItemScene::ItemScene()
{
	ItemDataes temp;
	_inventory = make_shared<Inventery>(Vector2(300.0f, 400.0f));


}

ItemScene::~ItemScene()
{

}

void ItemScene::Update()
{

	_inventory->Update();

}

void ItemScene::Render()
{
	_inventory->Render();
}

void ItemScene::PreRender()
{
	_inventory->SetRTV();

}

void ItemScene::PostRender()
{

}
