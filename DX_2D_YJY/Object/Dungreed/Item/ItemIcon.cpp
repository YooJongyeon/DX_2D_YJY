#include "framework.h"
#include "ItemIcon.h"

ItemIcon::ItemIcon(wstring file, Vector2 maxFrame)
{
	_quad = make_shared<Quad>(L"Resource/Item/Item_11x5.png", L"Shaders/InstancingVertexShader.hlsl", L"Shaders/InstancingPixelShader.hlsl");
	_instancingDataes.resize(_poolCount);

	for (auto& data : _instancingDataes)
	{
		Transform transform;
		transform.GetPos() = { (float)MathUtillty::RandomInt(0,WIN_WIDTH), (float)MathUtillty::RandomInt(0,WIN_HEIGHT) };
		transform.GetScale() *= MathUtillty::RandomFloat(0.0f, 0.2f);

		transform.UpdateWorldBuffer();

		data.matrix = XMMatrixTranspose(transform.GetMatrix());

		data.maxFrame = { 10,8 };
		data.curFrame = { MathUtillty::RandomInt(0,10), MathUtillty::RandomInt(0,8) };
		
	}

	_instancingBuffer = make_shared<VertexBuffer>(_instancingDataes.data(), sizeof(InstancingDataes), _poolCount);

}

ItemIcon::~ItemIcon()
{
}
