cbuffer FillterInfo : register(b0)
{
	int selected;
	int value1;
	int value2;
	int value3;
}

Texture2D map : register(t0); // srv
SamplerState samp : register(s0); // sampler

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

float4 Mosaic(float2 uv)
{

	int x = floor(uv.x * value1);
	int y = floor(uv.y * value1);

	float2 temp;
	temp.x = (float)x / value1;
	temp.y = (float)y / value1;

	return map.Sample(samp, temp);
}

float4 PS(PixelInput input) : SV_TARGET
{
	return Mosaic(input.uv);
}