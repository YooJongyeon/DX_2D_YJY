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
	_bulton->SetPosition(Vector2(100, WIN_HEIGHT - 100));
	_bulton->SeText("Button");
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

	Vector2 mP = Camera::GetInstance()->GetMouseWorldPos();

	if (_bulton->GetRectCollider()->IsCollision(mP))
	{
		_bulton->GetRectCollider()->SetRed();
	}
	else
	{
		_bulton->GetRectCollider()->SetGreen();
	}
}

void CameraScene::Render()
{
	_backGround->Render();
	_zelda->Render();
	
}

void CameraScene::PostRender()
{
	if (ImGui::Button("Save", {100,100}))
		SavePos();
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



