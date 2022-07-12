#include "framework.h"
#include "FillterScene.h"

FillterScene::FillterScene()
{
	_quad = make_shared<Quad>(L"Resource/LostArk.png"
		,L"Shaders/TextureVertexShader.hlsl"
		, L"Shaders/FillterShader/FillterShader.hlsl");
	_quad->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };
	_quad->GetTransform()->GetScale() *= 0.5f;

	_filterBuffer = make_shared<FilterBuffer>();
	_filterBuffer->data.value1 = 60;

	_imageSizeBuffer = make_shared<ImageSizeBuffer>();
	_imageSizeBuffer->data.size = _quad->GetHalfSize() * 2.0f;

	_sun = make_shared<Quad>(L"Resource/sun.PNG",
		L"Shaders/TextureVertexShader.hlsl"
		, L"Shaders/FillterShader/FillterShader.hlsl");
	_sun->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };
	_sun->GetTransform()->GetScale() *= 0.2f;
	_sunFilterBuffer = make_shared<FilterBuffer>();
	_sunFilterBuffer->data.selected = 6;

	_effect = make_shared<Effect>(L"Resource/Effects/skill_core_4x4.png", Vector2{ 4,4 }, 0.1f);
}

FillterScene::~FillterScene()
{
}

void FillterScene::Update()
{
	_quad->Update();
}

void FillterScene::Render()
{
	_quad->Render();
	_filterBuffer->SetPSBuffer(0);
}

void FillterScene::PostRender()
{
	ImGui::SliderInt("Mosaic", &(_filterBuffer->data.value1), 0, 2160);
}
