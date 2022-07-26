#pragma once
class XmlLoadScene : public Scene
{
public:
	XmlLoadScene();
	virtual ~XmlLoadScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<ItemDataes> _data;
};

