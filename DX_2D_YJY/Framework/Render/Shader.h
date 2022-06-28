#pragma once
class Shader
{
public:
	Shader();
	~Shader();

private:
	Microsoft::WRL::ComPtr<ID3DBlob> _blob;
};

