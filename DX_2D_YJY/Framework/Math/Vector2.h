#pragma once
 class Vector2 : public XMFLOAT2
{
public:
	Vector2() {}
	Vector2(float x, float y) :XMFLOAT2(x,y){}
	~Vector2() {}

	Vector2 operator+(const Vector2& value) const;
	Vector2& operator+=(const Vector2& value) ;
	Vector2 operator-(const Vector2& value) const;
	Vector2& operator-=(const Vector2& value);
	Vector2 operator*(const float& value) const;
	Vector2& operator*=(const float& value);

	bool operator==(const Vector2 value) const;
	bool operator!=(const Vector2 value) const;

	bool operator<(const Vector2 value) const;

	float Length() const;
	float Distance(const Vector2& pos) const;

	Vector2 NormalVector();
	void Normallize();

	float Dot(const Vector2& value);
	float Shadow(const Vector2& floor);

	float Cross(const Vector2& value);

	void YAxisSymmetry();
	int Manhattan(const Vector2& value) const;

	float Angle() const;
	float Angle(const Vector2& value) const;

	


	
};

