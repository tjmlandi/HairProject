#pragma once

#include "DXCore.h"
#include "SimpleShader.h"
#include <DirectXMath.h>
#include <WICTextureLoader.h>


class Material
{
	SimpleVertexShader* vertexShader;
	SimplePixelShader* pixelShader;
	ID3D11ShaderResourceView* textureView;
	ID3D11SamplerState* samplerState;
public:
	Material(SimpleVertexShader* newVertexShader, SimplePixelShader* newPixelShader, ID3D11ShaderResourceView* newTextureView,	ID3D11SamplerState* newSamplerState);
	~Material();
	SimpleVertexShader* getVertexShader();
	SimplePixelShader* getPixelShader();
	ID3D11ShaderResourceView* getTextureView();
	ID3D11SamplerState* getSamplerState();
};

