#include "framework.h"
#include "Audio.h"

Audio* Audio::_instance = nullptr;
Audio::Audio()
{
	System_Create(&_soundSystem);
	_soundSystem->init(MAX_CHAANEL, FMOD_INIT_NORMAL, nullptr);

}

Audio::~Audio()
{
	for (auto& info : _soundMap)
		delete info.second;
	_soundSystem->release();
}

void Audio::Update()
{
	_soundSystem->update();
}

void Audio::Add(string key, string file, bool bgm)
{
	if (_soundMap.count(key)>0)
		return;
	SoundInfo* info = new SoundInfo();

	if (bgm)
		_soundSystem->createStream(file.c_str(), FMOD_LOOP_NORMAL, nullptr, IN & info->sound);
	else
		_soundSystem->createStream(file.c_str(), FMOD_DEFAULT, nullptr, IN & info->sound);
	
	_soundMap[key] = info;
}

void Audio::Play(string key, float volume)
{
	if (_soundMap.count(key)==0)
		return;

	_soundSystem->playSound(_soundMap[key]->sound, nullptr, false, IN & _soundMap[key]->channel);
	_soundMap[key]->channel->setVolume(volume);
	
}

void Audio::Stop(string key)
{
	if (_soundMap.count(key) == 0)
		return;
	_soundMap[key]->channel->setPaused(true);
}

void Audio::Pause(string key)
{
	if (_soundMap.count(key) == 0)
		return;
	_soundMap[key]->channel->setPaused(true);
}

void Audio::Resume(string key)
{
	if (_soundMap.count(key) == 0)
		return;
	_soundMap[key]->channel->setPaused(false);
}

bool Audio::IsPlaySound(string key)
{
	if (_soundMap.count(key) == 0)
		return false;

	bool isPlay = false;
	_soundMap[key]->channel->isPlaying(IN & isPlay);

	return isPlay;
}
