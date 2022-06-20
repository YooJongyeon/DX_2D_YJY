#pragma once
class Bullet
{
public:
	Bullet();
	~Bullet();

	void Update();
	void Render();


	
	void SetDirection(Vector2 dir);
	void SetMovePostion(const Vector2& vector) { _movePosition = vector; }
	void SetPosition(const Vector2& vector) { _redBullet->GetTransform()->m_pos = vector; }
	bool _isActive = false;

private:
	shared_ptr<Texture> _redBullet;

	Vector2 _movePosition;

	float _checkTime = 0.0f;


};

