#include "framework.h"
#include "InstancingScene.h"

InstancingScene::InstancingScene()
{
	/*_quads.reserve(_poolCount);
	for (int i = 0; i < _poolCount; i++)
	{
		shared_ptr<Quad> quad = make_shared<Quad>(L"Resource/adventure.png");
		quad->GetTransform()->GetPos() = { MathUtillty::RandomInt(0,WIN_WIDTH),MathUtillty::RandomInt(0,WIN_HEIGHT) };
		quad->GetTransform()->GetScale() *= MathUtillty::RandomFloat(0.0f, 1.0f);
		_quads.emplace_back(quad);

	}*/

	_quads = make_shared<Quad>(L"Resource/adventure.png",L"Shaders/InstancingVertexShader.hlsl", L"Shaders/InstancingPixelShader.hlsl");
	_instancingDataes.resize(_poolCount);

	for (auto& matrix : _instancingDataes)
	{
		Transform transform;
		transform.GetPos() = { (float)MathUtillty::RandomInt(0,WIN_WIDTH), (float)MathUtillty::RandomInt(0,WIN_HEIGHT) };
		transform.GetScale() *= MathUtillty::RandomFloat(0.0f, 1.0f);

		transform.UpdateWorldBuffer();

		matrix = XMMatrixTranspose(transform.GetMatrix());
	}

	_instancingBuffer = make_shared<VertexBuffer>(_instancingDataes.data(), sizeof(XMMATRIX), _poolCount);
}

InstancingScene::~InstancingScene()
{
}

void InstancingScene::Update()
{
	
	_quads->Update();

}

void InstancingScene::Render()
{
	_instancingBuffer->IASet(1);

	_quads->SetRender();

	DEVICE_CONTEXT->DrawIndexedInstanced(6, _poolCount, 0, 0, 0);

}
