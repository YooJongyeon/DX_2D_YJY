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
	shared_ptr<VertexShader> AddVS(wstring file);
	shared_ptr<PixelShader> AddPS(wstring file);


private:
	static ShaderManger* _instance;
	unordered_map<wstring, shared_ptr<Shader>> _shadersMap;
};

