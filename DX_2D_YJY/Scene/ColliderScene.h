#pragma once
class ColliderScene : public Scene
{

public:
	ColliderScene();
	virtual ~ColliderScene();
	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender()override;

private:
	shared_ptr<RectCollider> _rectCollider1;
	shared_ptr<RectCollider> _rectCollider2;

	shared_ptr<CircleCollider> _circleCollider;


};

