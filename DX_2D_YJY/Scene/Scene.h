#pragma once
class Scene
{
public:
	Scene();
	virtual ~Scene();

	virtual void Update() abstract;
	virtual void Render() abstract;
	virtual void RreRender() {}
	virtual void PostRender() {}

private:
};

