cbuffer BgOrSlot : register(b0)
{
	int bgOrSlot;
	float padding0;
	float padding1;
	float padding2;
}

Texture2D map : register(t0); // srv
SamplerState samp : register(s0); // sampler

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// SV_TARGET : 그릴 곳... 우리한테는 후면버퍼
float4 PS(PixelInput input) : SV_TARGET
{
	if (bgOrSlot == 0)
		return float4(0.8f, 0.8f, 0.8f, 0.8f);

	return float4(0.3f,0.3f,0.3f,0.8f);
}