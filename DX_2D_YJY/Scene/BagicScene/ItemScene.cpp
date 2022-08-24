#include "framework.h"
#include "ItemScene.h"

ItemScene::ItemScene()
{
	_itemDataes = make_shared<ItemDataes>();
	_inventory = make_shared<Inventery>(Vector2(300.0f, 400.0f));
	_inventory->AddItme(*_itemDataes->FindItem("Sword_1"));
	_inventory->AddItme(*_itemDataes->FindItem("Sword_1"));
	

	_store = make_shared<Store>(Vector2(300.0f, 400.0f));


}

ItemScene::~ItemScene()
{

}

void ItemScene::Update()
{

	_inventory->Update();
	_store->Update();

}

void ItemScene::Render()
{
	
}

void ItemScene::PreRender()
{
	_inventory->SetRTV();

}

void ItemScene::PostRender()
{
	_inventory->PostRender();
	_store->PostRender();
}

void ItemScene::Init()
{
}
