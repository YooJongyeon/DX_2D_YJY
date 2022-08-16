#pragma once

class Sprite :public Quad
{
public:
	Sprite(wstring file, Vector2 maxFrame = Vector2{ 1,1 });
	~Sprite();

	virtual void Update() override;
	virtual void Render() override;

	virtual void CreateData() override;
	
	Vector2 GetHalfFrameSize();
	void SetFrameBuffer(int x, int y) { _frameBuffer->data.curFrame = { (float)x,(float)y }; }
	void SetClipToActionBuffer(Action::Clip clip);
	void SetClip(Action::Clip clip);

	float Top() { return _transform->GetWorldPos().y + (GetHalfFrameSize().y * _transform->GetWorldScale().y); }
	float Bottom() { return _transform->GetWorldPos().y - (GetHalfFrameSize().y * _transform->GetWorldScale().y); }
	float Right() { return _transform->GetWorldPos().x + (GetHalfFrameSize().x * _transform->GetWorldScale().x); }
	float Left() { return _transform->GetWorldPos().x - (GetHalfFrameSize().x * _transform->GetWorldScale().x); }

	bool _isActive = true;

private:
	Vector2 _maxFrame;
	shared_ptr<FrameBuffer> _frameBuffer;
	shared_ptr<ActionBuffer> _actionBuffer;

	
};

