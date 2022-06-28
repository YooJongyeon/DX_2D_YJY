#pragma once
class VertexShader
{
	//friend class ShaderManger();
	
public:
	VertexShader(wstring file);
	~VertexShader();

	void CreateBlob(wstring file);
	void CreateInputLayOut();
	void CreateVertexShader();

	void Set();

private:
	Microsoft::WRL::ComPtr<ID3D11VertexShader> _vertexShader;
	Microsoft::WRL::ComPtr<ID3D11InputLayout> _inputLayout;
	Microsoft::WRL::ComPtr<ID3D11ShaderReflection> _reflection;
	Microsoft::WRL::ComPtr<ID3DBlob> _vertexBlob;
};

