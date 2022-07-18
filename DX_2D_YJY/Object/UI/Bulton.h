#pragma once
class Bulton
{
public:
	enum BultonState
	{
		NOME,
		HOVER,
		CLICK
	};


	Bulton();
	~Bulton();

	void Update();
	void PostRender();

	void SetPosition(Vector2 pos);
	void SetScale(Vector2 scale);
	void SeText(string text);

	shared_ptr<RectCollider> GetRectCollider() { return _col; }

private:
	BultonState _stae;

	shared_ptr<Quad> _quad;
	shared_ptr<RectCollider> _col;
	string _text;

	Vector2 _textPos;
	
};

