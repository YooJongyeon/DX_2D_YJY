#include "framework.h"
#include "CameraScene.h"

CameraScene::CameraScene()
{
	_backGround = make_shared<Quad>(L"Resource/LostArk.png");
	_backGround->GetTransform()->GetPos().x *= _backGround->GetHalfSize().x;
	_backGround->GetTransform()->GetPos().y *= _backGround->GetHalfSize().y;


	_zelda = make_shared<Zelda>();

	_zeldaFollowTrans = make_shared<Transform>();
	Vector2 temp = this->LoadPos();
	_zelda->SetPostion(temp.x, temp.y);
	_zeldaFollowTrans->GetPos() = _zelda->GetTransform()->GetPos();

	Camera::GetInstance()->SetTarget(_zeldaFollowTrans);
	Vector2 leftBottom = {0,0};
	Vector2 rightTop = { _backGround->GetHalfSize().x  , _backGround->GetHalfSize().y};
	Camera::GetInstance()->SetLeftBottom(leftBottom);
	Camera::GetInstance()->SetRightTop(rightTop);

	_bulton = make_shared<Bulton>();
	_bulton->SetScale(Vector2(0.1f, 0.1f));
	_bulton->SetPosition({ 100,WIN_HEIGHT - 100 });
	_bulton->SetText("Save");

	_bulton->SetEvent(std::bind(&CameraScene::SavePos, this));
	_bulton->SetEventParam(std::bind(&CameraScene::Test, this, placeholders::_1), 13);


	_miniMap = make_shared<MinMap>(_backGround->GetHalfSize() * 0.2);
	_miniMap->SetBackGround(leftBottom, rightTop);
	_miniMap->SetPlayerPos(&_zelda->GetTransform()->GetPos());
	

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
	_miniMap->Update();
}

void CameraScene::Render()
{
	_backGround->Render();
	_zelda->Render();
	
	
}

void CameraScene::PreRender()
{

	ALPHA_STATE->SetState();
	_miniMap->SetRTV();
	
}

void CameraScene::PostRender()
{
	_bulton->PostRender();
	_miniMap->PostRender();

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

void CameraScene::Test(int test)
{
	int a = test;
}




