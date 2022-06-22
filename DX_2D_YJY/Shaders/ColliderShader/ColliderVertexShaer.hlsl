cbuffer World : register(b0)
{
	matrix world;
}

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

};


struct VertexOutput
{
	float4 pos : SV_POSITION;
};

// VertexShader
// SV : System Value
VertexOutput VS(VertexInput input)
{
	matrix wvp = mul(world, view);
	wvp = mul(wvp, projection);

	VertexOutput output;
	output.pos = mul(input.pos, wvp);

	return output;
}