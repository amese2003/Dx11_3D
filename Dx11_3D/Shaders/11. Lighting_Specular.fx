#include "00. Global.fx"

float3 LightDir;
float4 LightSpecular;
float4 MaterialSpecular;
Texture2D DiffuseMap;

MeshOutput VS(VertexTextureNormal input)
{
	MeshOutput output;
	output.position = mul(input.position, W);
	output.worldPosition = input.position;
	output.position = mul(output.position, VP);
	output.uv = input.uv;
	output.normal = mul(input.normal, (float3x3)W);

	return output;
}

// Specular (�ݻ籤)
// �ѹ������� ������ �ݻ�Ǵ� ��
float4 PS(MeshOutput input) : SV_TARGET
{
	//float R = reflect(LightDir, input.normal);
	float3 R = LightDir - (2 * input.normal * dot(LightDir, input.normal));
	R = normalize(R);

	float3 cameraPosition = -V._41_42_43;
	float3 E = normalize(cameraPosition - input.worldPosition);

	float value = saturate(dot(R, E)); // Clamp01
	float specular = pow(value, 10);

	float4 color = LightSpecular * MaterialSpecular * specular;
	
	return color; 
}

technique11 T0
{
	PASS_VP(P0, VS, PS)
};