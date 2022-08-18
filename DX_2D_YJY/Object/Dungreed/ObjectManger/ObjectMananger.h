#pragma once
class ObjectMananger
{
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new ObjectMananger();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static ObjectMananger* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
	}

public:
	// 싱글턴
	void Add(wstring bossFile, Vector2 maxFrame, float speed, UINT poolCount = 30); // _effectMap에 추가
	void Play(string boss, Vector2 pos); // _effectMap에서 꺼져있는 얘 찾아서 플레이 시키는 얘

	void Update(); // _effectMap Update
	void Render(); // _effectMap Render

private:
	ObjectMananger();
	~ObjectMananger();
	
private:
	static ObjectMananger* _instance;
	unordered_map<string, vector<shared_ptr<Object>>> _objectMap;
};

