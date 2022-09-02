struct VS_Out
{
  float4 position : SV_POSITION;
  float2 texCoord : TexCoord;
};

struct VS_In
{
  float4 position : Position;
  float2 texCoord : TexCoord;
};

VS_Out main(VS_In input)
{
  VS_Out output;

  output.position = input.position;
  output.texCoord = input.texCoord;

  return output;
}