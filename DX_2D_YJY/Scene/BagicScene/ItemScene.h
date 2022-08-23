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


private:
	shared_ptr<ItemDataes> _itemData;
	shared_ptr<Inventery> _inventory;

};

