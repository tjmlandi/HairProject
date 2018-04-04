#include "Material.h"




Material::Material(SimpleVertexShader * newVertexShader, SimplePixelShader * newPixelShader, ID3D11ShaderResourceView* newTextureView, ID3D11SamplerState* newSamplerState)
{
	this->pixelShader = newPixelShader;
	this->vertexShader = newVertexShader;
	this->textureView = newTextureView;
	this->samplerState = newSamplerState;
}

Material::~Material()
{
}

SimpleVertexShader * Material::getVertexShader()
{
	return this->vertexShader;
}

SimplePixelShader * Material::getPixelShader()
{
	return this->pixelShader;
}

ID3D11ShaderResourceView * Material::getTextureView()
{
	return this->textureView;
}

ID3D11SamplerState * Material::getSamplerState()
{
	return this->samplerState;
}
