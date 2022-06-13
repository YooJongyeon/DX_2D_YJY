Texture2D map : register(t0); // srv
SamplerState samp : register(s0); // sampler

struct VertexInput
{
	float4 pos : POSITION;
	float2 uv : UV;
};

struct PixelInput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// VertexShader
// SV : System Value
PixelInput VS(VertexInput input)
{
	PixelInput output;
	output.pos = input.pos;
	output.uv = input.uv;

	return output;
}

// SV_TARGET : 그릴 곳... 우리한테는 후면버퍼
float4 PS(PixelInput input) : SV_TARGET
{
	float4 result = map.Sample(samp,input.uv);

	return result;
}