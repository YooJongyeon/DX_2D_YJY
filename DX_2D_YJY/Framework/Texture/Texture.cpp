#include "framework.h"
#include "Texture.h"

unordered_map<wstring, shared_ptr<Texture>> Texture ::_texturesMap;

Texture::Texture(Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> srv, ScratchImage& image)
	:_srv(srv)
	, _image(std::move(image))
{
}
Texture::~Texture()
{
}
shared_ptr<Texture> Texture::Add(wstring file)
{
	if (_texturesMap.count(file) > 0)
	{
		return _texturesMap[file];
	}

	ScratchImage Image;

	LoadFromWICFile(&file[0], WIC_FLAGS_NONE, nullptr, Image);
	Microsoft::WRL::ComPtr<ID3D11ShaderResourceView> srv;

	CreateShaderResourceView(DEVICE.Get(), Image.GetImages(), Image.GetImageCount(), Image.GetMetadata(), srv.GetAddressOf());

	shared_ptr<Texture> texture = make_shared<Texture>(srv, Image);
	texture->_file = file;

	_texturesMap[file] = texture;

	return 	_texturesMap[file];
}

void Texture::Delete()
{
}

void Texture::Set(UINT slot)
{
	DEVICE_CONTEXT->PSSetShaderResources(slot, 1, _srv.GetAddressOf());
}

Vector2 Texture::Getsize()
{
	return Vector2(_image.GetMetadata().width, _image.GetMetadata().height);
}

