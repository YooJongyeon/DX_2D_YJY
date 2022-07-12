#pragma once
class FillterScene : public Scene
{
public:
	FillterScene();
	virtual ~FillterScene();

	virtual void Update() override;
	virtual void Render() override;
	virtual void PostRender() override;
private:
	shared_ptr<Quad> _quad;
	shared_ptr<FilterBuffer> _filterBuffer;
	shared_ptr<ImageSizeBuffer> _imageSizeBuffer;

	shared_ptr<Quad> _sun;
	shared_ptr<FilterBuffer> _sunFilterBuffer;

	shared_ptr<Effect> _effect;
};



