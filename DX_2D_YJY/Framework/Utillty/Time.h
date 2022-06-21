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

	double GetDeltamTime() { return _timeTiclElased; }
	int GetFPS() { return _frameRate; }
	void SetFPS(double fps) { _lockFPS = fps; }

	double GetRunTime() { return _runTime; }

private:
	static Time* _instacne;

	double _timeScale;
	double _timeTiclElased;

	__int64 _curTime;
	__int64 _lastTime;
	__int64 _periodFrequency;

	int _frameRate;
	int _frameCount;

	double _oneSecCount;
	double _runTime;

	double _lockFPS;
};

