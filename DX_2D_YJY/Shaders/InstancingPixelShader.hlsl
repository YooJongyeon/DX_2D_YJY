Texture2D map : register(t0); // srv
SamplerState samp : register(s0); // sampler

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;

	float2 curFrame : CURFRAME;
	float2 maxFrame : MAXFRAME;

};

// SV_TARGET : 그릴 곳... 우리한테는 후면버퍼
float4 PS(PixelInput input) : SV_TARGET
{
	float2 uv;

	uv.x = input.uv.x / input.maxFrame.x + (input.curFrame.x / input.maxFrame.x); 
	uv.y = input.uv.y / input.maxFrame.y + (input.curFrame.y / input.maxFrame.y);

	float4 result = map.Sample(samp,uv);

	return result;
}