cbuffer View : register(b1)
{
	matrix view;
}

cbuffer Projection : register(b2)
{
	matrix projection;
}

struct VertexInput
{
	float4 pos : POSITION;
	float2 uv : UV;

	matrix transform : INSTANCE_TRANSFORM;
};

struct VertexOutput
{
	float4 pos : SV_POSITION;
	float2 uv : UV;
};

// VertexShader
// SV : System Value
VertexOutput VS(VertexInput input)
{
	matrix wvp = mul(input.transform, view);
	wvp = mul(wvp, projection);

	VertexOutput output;
	output.pos = mul(input.pos, wvp);
	output.uv = input.uv;

	return output;
}