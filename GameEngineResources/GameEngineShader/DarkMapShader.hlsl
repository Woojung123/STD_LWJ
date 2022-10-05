// #include "myshader.hlsli"

// SV_POSITION �ø�ƽ
// �׷���ī�忡�� �̳༮�� �̷� �η��ϱ� �ϰ� �ڵ����� ó���ϴ� �༮�� ������ �ϰ�.

#include "TransformHeader.fx"
#include "RenderOption.fx"


// 0                                                                                                1 
// 0��������
struct Input
{
    float4 Pos : POSITION;
    float4 Tex : TEXCOORD;


    // �ν��Ͻ� ������
    uint Index : ROWINDEX;
};



struct Output
{
    float4 Pos : SV_POSITION;
    float4 PosLocal : POSITION;
    float4 Tex : TEXCOORD;
};

// 1000
// 0100
// 2010
// 0301

// 1020
// 0103
// 0010
// 0001

cbuffer AtlasData : register(b1)
{
    float2 TextureFramePos;
    float2 TextureFrameSize;
    float4 PivotPos;
};


Output DarkMapShader_VS(Input _Input)
{
    
    Output NewOutPut = (Output)0;
    _Input.Pos += PivotPos;
    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;


    NewOutPut.Tex.x = (_Input.Tex.x * TextureFrameSize.x) + TextureFramePos.x;
    NewOutPut.Tex.y = (_Input.Tex.y * TextureFrameSize.y) + TextureFramePos.y;

    return NewOutPut;
}



Output DarkMapShader_VSINST(Input _Input)
{
    // -0.5, 0.5,     0.5 0.5
    // 0.5, 0.5,     0.5 0.5

    Output NewOutPut = (Output)0;
    _Input.Pos += PivotPos;
    NewOutPut.Pos = mul(_Input.Pos, WorldViewProjection);
    NewOutPut.PosLocal = _Input.Pos;

    // ���ؽ��� ���° ���ؽ� ���� �˼��� ����.
    // NewOutPut.Tex
    // 00    10

    //// 10    11

    //TextureFrameSize.x -= 0.5f;
    //TextureFrameSize.y -= 0.5f;
    //TextureFramePos.x -= 0.5f;
    //TextureFramePos.y -= 0.5f;

    NewOutPut.Tex.x = (_Input.Tex.x * TextureFrameSize.x) + TextureFramePos.x;
    NewOutPut.Tex.y = (_Input.Tex.y * TextureFrameSize.y) + TextureFramePos.y;

    return NewOutPut;
}



cbuffer PixelData : register(b0)
{
    float4 MulColor;
    float4 PlusColor;
    float4 Slice;
}





Texture2D Tex : register(t0);
SamplerState Smp : register(s0);
float4 DarkMapShader_PS(Output _Input) : SV_Target0
{



    if (_Input.PosLocal.x < -0.05 && _Input.PosLocal.y > -0.3)
    {
        clip(-1);
    }


   float4 TexColor = Tex.Sample(Smp, _Input.Tex.xy);

   float4 InputPos = float4(_Input.Pos.x, _Input.Pos.y,0.0f,0.0f);
   float4 SlicePos = float4(Slice.x, Slice.y, 0.0f, 0.0f);

   float len = length(InputPos - SlicePos);

   if (Slice.z >= 80.f)
   {
       if (len <= 25.f)
       {

          TexColor.a = len / 25.f;
         
       }

       if (TexColor.a == 0)
       {
           clip(-1);
       }


       return (TexColor * MulColor) + PlusColor;

   }


      if (len <= 600.f)
       {

           TexColor.a = len / 600.f;


       }

   
   


    if (TexColor.a == 0)
    {
        clip(-1);
    }


    return (TexColor * MulColor) + PlusColor;
}
