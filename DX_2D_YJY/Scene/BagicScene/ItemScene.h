#pragma once
class ItemScene : public Scene
{
public:

	ItemScene();
	virtual ~ItemScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PreRender() override;
	virtual void PostRender() override;
	virtual void Init() override;


private:
	shared_ptr<ItemDataes> _itemDataes;
	shared_ptr<Inventery> _inventory;
	shared_ptr<Store> _store;

};

