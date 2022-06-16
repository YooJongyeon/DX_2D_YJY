#pragma once
class SolarSystemScene : public Scene
{
public:
	SolarSystemScene();
	virtual ~SolarSystemScene();

	// Scene��(��) ���� ��ӵ�
	virtual void Update() override;
	virtual void Render() override;
private:
	shared_ptr<Texture> _sun;
	shared_ptr<Texture> _earth;
	shared_ptr<Texture> _moon;

	shared_ptr<SamplerState> _samplerState;
	shared_ptr<BlendState> _blendState;
};


