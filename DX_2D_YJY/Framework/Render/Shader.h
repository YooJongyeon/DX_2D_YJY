#pragma once
class Shader 
{
public:
	Shader();
	~Shader();

	virtual void Set() abstract;

protected:
	Microsoft::WRL::ComPtr<ID3DBlob> _blob;
};

