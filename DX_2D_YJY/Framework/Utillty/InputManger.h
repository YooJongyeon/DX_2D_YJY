#pragma once

#define KEYMAX 255

class InputManger
{
private:
	enum
	{
		NONE,
		DOWN,
		UP,
		PRESS
	};

	InputManger();
	~InputManger();

public:
	static void Create()
	{
		if (_instacne == nullptr)
		{
			_instacne = new InputManger();
		}
	}

	static void Delete()
	{
		if (_instacne != nullptr)
			delete _instacne;

		_instacne = nullptr;
	}

	static InputManger* GetInstance()
	{
		if (_instacne != nullptr)
			return _instacne;

		return nullptr;
	}

	void Update();

	bool Down(UINT key) { return _mapState[key] == DOWN; }
	bool Up(UINT key) { return _mapState[key] == UP; }
	bool Press(UINT key) { return _mapState[key] == PRESS; }

	Vector2& GetMousePos() { return  _mousePos; }


private:
	static InputManger* _instacne;

	byte _curState[KEYMAX];
	byte _oldState[KEYMAX];
	byte _mapState[KEYMAX];


	Vector2 _mousePos = { 0.0f,0.0f };

};

