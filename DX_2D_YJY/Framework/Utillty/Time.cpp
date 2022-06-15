#include "framework.h"
#include "Time.h"

Time* Time::_instacne = nullptr;

Time::Time()
{

	QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency);
	
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

	_timeScale = 1.0f / (double)_periodFrequency;

}

Time::~Time()
{
}

void Time::Update()
{
	QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	
	if (_lockFPS != 0)
	{
		while (_timeTiclElased <(1.0 / _lockFPS))
		{
			QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			_timeTiclElased = (double)(_curTime - _lastTime) * _timeScale;
		}
	}
	else
	{
		_timeTiclElased = (double)(_curTime - _lastTime) * _timeScale;
	}
	_lastTime = _curTime;

	_frameCount++;
	_oneSecCount += _timeTiclElased;
	_runTime += _timeTiclElased;

	//1초마다 갱신해야 되는 정보
	if (_oneSecCount >= 1.0)
	{
		_oneSecCount = 0;
		_frameCount = 0;

		_frameRate = _frameCount;
	}
}
