#pragma once
class EffectManager
{
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new EffectManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static EffectManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
	}

public:
	// �̱���
	void Add(wstring effectFile, Vector2 maxFrame, float speed, UINT poolCount = 30); // _effectMap�� �߰�
	void Play(string effect, Vector2 pos); // _effectMap���� �����ִ� �� ã�Ƽ� �÷��� ��Ű�� ��

	void Update(); // _effectMap Update
	void Render(); // _effectMap Render

private:
	EffectManager();
	~EffectManager();

private:
	static EffectManager* _instance;
	unordered_map<string, vector<shared_ptr<Effect>>> _effectMap;
};

