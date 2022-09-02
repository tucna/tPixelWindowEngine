Texture2D tex : register(t0);
SamplerState samplerState : register(s0);

float4 main(float4 position : SV_POSITION, float2 texCoord : TexCoord) : SV_Target
{
  return tex.Sample(samplerState, texCoord);
}