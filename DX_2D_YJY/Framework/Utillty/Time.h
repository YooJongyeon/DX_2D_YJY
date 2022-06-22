#pragma once
class Time
{
private:
	Time();
	~Time();

public:
	static void Create()
	{
		if (_instacne == nullptr)
		{
			_instacne = new Time();
		}
	}

	static void Delete()
	{
		if (_instacne != nullptr)
			delete _instacne;

		_instacne = nullptr;
	}

	static Time* GetInstance()
	{
		if (_instacne != nullptr)
			return _instacne;

		return nullptr;
	}

	void Update();

	double GetDeltamTime() { return _timeTickElased; }
	int GetFPS() { return _frameRate; }
	void SetFPS(double fps) { _lockFPS = fps; }

	double GetRunTime() { return _runTime; }

private:
	static Time* _instacne;

	double _timeScale = 0;
	double _timeTickElased = 0;

	__int64 _curTime = 0;
	__int64 _lastTime = 0;
	__int64 _periodFrequency = 0;

	int _frameRate = 0;
	int _frameCount = 0;

	double _oneSecCount = 0;
	double _runTime = 0;

	double _lockFPS = 0;
};

