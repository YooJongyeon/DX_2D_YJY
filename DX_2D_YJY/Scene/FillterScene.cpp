#include "framework.h"
#include "FillterScene.h"

FillterScene::FillterScene()
{
	_quad = make_shared<Quad>(L"Resource/LostArk.png"
		,L"Shaders/TextureVertexShader.hlsl"
		, L"Shaders/FillterShader/FillterShader.hlsl");
	_quad->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };
	_quad->GetTransform()->GetScale() *=1.5f;

	_filterBuffer = make_shared<FilterBuffer>();
	_filterBuffer->data.value1 = 60;

	_imgaeSizeBuffer = make_shared <ImageSizeBuffer>();
	_imgaeSizeBuffer->data.size = _quad->GetHalfSize()*2.0f;

	_sun = make_shared<Quad>(L"Resource/sun.PNG"
		, L"Shaders/TextureVertexShader.hlsl"
		, L"Shaders/FillterShader/FillterShader.hlsl");
	_sun->GetTransform()->GetPos() = { WIN_WIDTH * 0.5f , WIN_HEIGHT * 0.5f };
	_sun->GetTransform()->GetScale() *= 0.2f;

	_sunFilterBuffer = make_shared<FilterBuffer>();
	_sunFilterBuffer->data.selected = 6;
}

FillterScene::~FillterScene()
{
}

void FillterScene::Update()
{
	_quad->Update();
	_sun->Update();
}

void FillterScene::Render()
{
	_filterBuffer->SetPSBuffer(0);
	_imgaeSizeBuffer->SetPSBuffer(1);
	_quad->Render();

	_sunFilterBuffer->SetPSBuffer(0);
	_sun->Render();
}

void FillterScene::PostRender()
{
	ImGui::SliderInt("Select", &(_filterBuffer->data.selected), 0, 5);
	ImGui::SliderInt("Mosaic", &(_filterBuffer->data.value1), 0, 100);
	ImGui::SliderInt("Blur", &(_filterBuffer->data.value2), 0, 10);
	ImGui::SliderInt("Radial", &(_filterBuffer->data.value3), 0, 30);
}
