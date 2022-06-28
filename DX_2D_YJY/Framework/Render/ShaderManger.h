#pragma once
class ShaderManger
{
private:
	ShaderManger();
	~ShaderManger();

public:
	static void Create() 
	{
		if (_instance == nullptr)
		{
			_instance = new ShaderManger();
		}

	}

	static void Delete() 
	{
		if (_instance != nullptr)
			delete _instance;
		_instance = nullptr;

	}
	
	static ShaderManger* Getinstance()
	{
		if (_instance != nullptr)
			return _instance;

		return nullptr;

	}


private:
	static ShaderManger* _instance;
};

