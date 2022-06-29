#include "framework.h"
#include "ShaderManger.h"

ShaderManger* ShaderManger::_instance = nullptr;

ShaderManger::ShaderManger()
{
}

ShaderManger::~ShaderManger()
{
}

shared_ptr<VertexShader> ShaderManger::AddVS(wstring file)
{
	if (_shadersMap.count(file) > 0)
	{
		return dynamic_pointer_cast<VertexShader>(_shadersMap[file]);
	}

	shared_ptr<VertexShader> vs = make_shared<VertexShader>(file);
		_shadersMap[file] = vs;

	return vs;
}

shared_ptr<PixelShader> ShaderManger::AddPS(wstring file)
{
	if(_shadersMap.count(file) > 0)
	{
		return dynamic_pointer_cast<PixelShader>(_shadersMap[file]);
	}

	shared_ptr<PixelShader> ps = make_shared<PixelShader>(file);
	_shadersMap[file] = ps;

	return ps;
}
