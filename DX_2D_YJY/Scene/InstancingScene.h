#pragma once
class InstancingScene :public Scene
{
public:
	InstancingScene();
	virtual ~InstancingScene();

	virtual void Update() override;
	virtual void Render() override;



private:
	shared_ptr<Quad> _quads;

	vector<XMMATRIX> _instancingDataes;
	shared_ptr<VertexBuffer> _instancingBuffer;

	UINT _poolCount = 10;
};

