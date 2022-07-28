#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	_backGround = make_shared<Quad>(L"Resource/LostArk.png");

	_zelda = make_shared<Zelda>();

	_zeldaFollowTrans = make_shared<Transform>();
	Vector2 temp = this->LoadPos();
	_zelda->SetPostion(temp.x, temp.y);
	_zeldaFollowTrans->GetPos() = _zelda->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_zeldaFollowTrans);
	Vector2 leftBottom = { -_backGround->GetHalfSize().x, -_backGround->GetHalfSize().y };
	Vector2 rightTop = { _backGround->GetHalfSize().x, _backGround->GetHalfSize().y };
	Camera::GetInstance()->SetLeftBottom(leftBottom);
	Camera::GetInstance()->SetRightTop(rightTop);

	_bulton = make_shared<Bulton>();
	_bulton->SetScale(Vector2(0.1f, 0.1f));
	_bulton->SetPosition({ 100,WIN_HEIGHT - 100 });
	_bulton->SetText("Save");

	_bulton->SetEvent(std::bind(&CameraScene::SavePos, this));
	_bulton->SetEventParam(std::bind(&CameraScene::Test, this, placeholders::_1), 13);

	// RenderTarget
	_rtv = make_shared<RenderTarget>(500, 500);
	_targetTexture = make_shared<Quad>(L"RenderTarget", _backGround->GetHalfSize());
	shared_ptr<Texture> texture = Texture::Add(L"Target", _rtv->GetSRV());
	_targetTexture->SetTexture(texture);
	_targetTexture->GetTransform()->GetPos() = { 0,0 };
	_targetTexture->GetTransform()->GetScale() *= 0.1f;
	_miniPlayer = make_shared<Quad>(L"Resource/monster.png");

}

CameraScene::~CameraScene()
{
}

void CameraScene::Update()
{
	_backGround->Update();
	_zelda->Update();

	float distance = _zelda->GetTransform()->GetPos().Distance(_zeldaFollowTrans->GetPos());
	if (distance >= 30.0f)
	{
		_zeldaFollowTrans->GetPos() = LERP(_zeldaFollowTrans->GetPos(), _zelda->GetTransform()->GetPos(), 0.001f);
	}
	_bulton->Update();

	_targetTexture->Update();
	_targetTexture->GetTransform()->GetPos() = 
		Camera::GetInstance()->GetTransform()->GetPos() + 
		Vector2(WIN_WIDTH - _targetTexture->GetHalfSize().x, WIN_HEIGHT - _targetTexture->GetHalfSize().y);

	Vector2 ratio;
	{
		//ratio.x = 
	}
	_miniPlayer->GetTransform()->GetPos();
	_miniPlayer->Update();
}

void CameraScene::Render()
{
	_backGround->Render();
	_zelda->Render();
	_miniPlayer->Render();
	
}

void CameraScene::PreRender()
{
	_rtv->Set();
	_miniPlayer->Render();
	ALPHA_STATE->SetState();

	//_zelda->Render();
	//_backGround->Render();
}

void CameraScene::PostRender()
{
	_bulton->PostRender();
}

void CameraScene::SavePos()
{
	BinaryWriter writer(L"Save/ZeldaInfo.zelda");
	
	vector<float> dataes;

	dataes.push_back(_zelda->GetTransform()->GetPos().x);
	dataes.push_back(_zelda->GetTransform()->GetPos().y);

	writer.Uint(dataes.size());
	writer.Uint(dataes.size() * sizeof(float));
	writer.Byte(dataes.data(), sizeof(float) * dataes.size());

}

Vector2 CameraScene::LoadPos()
{
	
	BinaryReader reader(L"Save/ZeldaInfo.zelda");

	UINT size = reader.Uint();
	UINT byteSize = reader.Uint();

	vector<float> dataes;
	dataes.resize(size);

	void* ptr = (void*)dataes.data();

	reader.Byte(&ptr, byteSize);

	Vector2 tempPos;

	if (dataes.size() == 0)
	{
		tempPos = { 0.0f,0.0f }; 
		return tempPos;
	}

	tempPos.x = dataes[0];
	tempPos.y = dataes[1];

	return tempPos;
}






