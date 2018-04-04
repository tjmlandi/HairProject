#pragma once

#include <d3d11.h>
#include <DirectXMath.h>
#include "Vertex.h"
#include "DXCore.h"
#include "SimpleShader.h"
#include "Material.h"
#include <fstream>

class Mesh
{
	ID3D11Buffer* indexBuffer;
	ID3D11Buffer* vertexBuffer;
	int indexBufferCount;
public:
	Mesh(Vertex * vertices, int numVert, unsigned int * indices, int numIndices, ID3D11Device * bufferCreator);
	Mesh(ID3D11Device * device, char* fileName);
	~Mesh();
	ID3D11Buffer* getVertexBuffer();
	ID3D11Buffer* getIndexBuffer();
	int getIndexCount();
};

