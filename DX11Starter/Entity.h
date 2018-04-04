#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include "Mesh.h"


using namespace DirectX;

class Entity
{
	XMFLOAT4X4 worldMatrix;
	XMFLOAT3 position;
	XMFLOAT3 rotation;
	XMFLOAT3 scale;
	bool hasMatrixChanged;
	Mesh* objectMesh;
	Material* material;
public:
	Entity(Mesh* newMesh, Material* newMaterial);
	~Entity();
	void updateMatrix();
	void prepareMaterials(XMFLOAT4X4 view, XMFLOAT4X4 projection);
	void setPosition(XMFLOAT3 newPosition);
	void setRotation(XMFLOAT3 newRotation);
	void setScale(XMFLOAT3 newScale);
	XMFLOAT3 getPosition();
	XMFLOAT3 getRotation();
	XMFLOAT3 getScale();
	XMFLOAT4X4 getWorldMatrix();
	Mesh* getMesh();
};

