#pragma once
class XmlLoadScene : public Scene
{
public:
	XmlLoadScene();
	virtual ~XmlLoadScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;

private:
	shared_ptr<ItemDataes> _data;
};

