#pragma once
class EnemyManager
{
public:
	static void Create()
	{
		if (_instance == nullptr)
			_instance = new EnemyManager();
	}

	static void Delete()
	{
		if (_instance != nullptr)
			delete _instance;
	}

	static EnemyManager* GetInstance()
	{
		if (_instance != nullptr)
			return _instance;
	}

public:
	// ╫л╠шео
	void Add(wstring enemyFile, Vector2 maxFrame, float speed, UINT poolCount = 30);
	void Play(string enemy, Vector2 pos);

	void Update();
	void Render(); 


	shared_ptr<Transform> GetTransform() { return _transform; }
private:
	EnemyManager();
	~EnemyManager();

private:
	static EnemyManager* _instance;
	unordered_map<string, vector<shared_ptr<Enemy>>> _enemyMap;
	shared_ptr<Transform> _transform;
};

