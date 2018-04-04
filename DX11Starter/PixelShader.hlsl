Texture2D diffuseTexture	: register (t0);
SamplerState basicSampler	: register (s0);


// Struct representing the data we expect to receive from earlier pipeline stages
// - Should match the output of our corresponding vertex shader
// - The name of the struct itself is unimportant
// - The variable names don't have to match other shaders (just the semantics)
// - Each variable must have a semantic, which defines its usage
struct VertexToPixel
{
	// Data type
	//  |
	//  |   Name          Semantic
	//  |    |                |
	//  v    v                v
	float4 position		: SV_POSITION;
	//float4 color		: COLOR;
	float3 normal		: NORMAL;
	float2 uvCoord		: TEXCOORD;
};

struct DirectionalLight
{
	float4 AmbientColor;
	float4 DiffuseColor;
	float3 Direction;
};

cbuffer externalData : register(b0)
{
	DirectionalLight light;
	DirectionalLight lightTwo;
};


// --------------------------------------------------------
// The entry point (main method) for our pixel shader
// 
// - Input is the data coming down the pipeline (defined by the struct)
// - Output is a single color (float4)
// - Has a special semantic (SV_TARGET), which means 
//    "put the output of this into the current render target"
// - Named "main" because that's the default the shader compiler looks for
// --------------------------------------------------------
float4 main(VertexToPixel input) : SV_TARGET
{
	// Just return the input color
	// - This color (like most values passing through the rasterizer) is 
	//   interpolated for each pixel between the corresponding vertices 
	//   of the triangle we're rendering
	float3 normal = normalize(input.normal);
	float3 newDirection = normalize(-light.Direction);
	float intensity = saturate(dot(normal, newDirection));

	float4 newLight = light.DiffuseColor * intensity;
	newLight += light.AmbientColor;


	float3 newDirectionTwo = normalize(-lightTwo.Direction);
	float intensityTwo = saturate(dot(normal, newDirectionTwo));

	float4 newLightTwo = lightTwo.DiffuseColor * intensityTwo;
	newLightTwo += lightTwo.AmbientColor;

	newLight += newLightTwo;

	float4 surfaceColor = diffuseTexture.Sample(basicSampler, input.uvCoord);

	newLight *= surfaceColor;

	return newLight;//input.color;
}