#pragma once
class TextureWVPScene : public Scene
{
public:
	TextureWVPScene();
	virtual ~TextureWVPScene();

	// Scene을(를) 통해 상속됨
	virtual void Update() override;
	virtual void Render() override;

private:
	shared_ptr<Quad> _quad;

	XMFLOAT2 _scale = { 1,1 };
	XMFLOAT2 _pos = { 0,0 };

	XMMATRIX _srt_matrix;

	shared_ptr<MatrixBuffer> _worldBuffer;
	XMFLOAT2 _worldPos = { 0,0 };

	XMFLOAT2 _cameraPos = { 0,0 };
	float _angle = { 0.0f };

	
};

