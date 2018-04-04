#pragma once

#include "DXCore.h"
#include "SimpleShader.h"
#include <DirectXMath.h>
#include <WICTextureLoader.h>
#include "Mesh.h"
#include "Entity.h"
#include "Camera.h"
#include "Material.h"
#include "Lights.h"

class Game 
	: public DXCore
{

public:
	Game(HINSTANCE hInstance);
	~Game();

	// Overridden setup and game loop methods, which
	// will be called automatically
	void Init();
	void OnResize();
	void Update(float deltaTime, float totalTime);
	void Draw(float deltaTime, float totalTime);

	// Overridden mouse input helper methods
	void OnMouseDown (WPARAM buttonState, int x, int y);
	void OnMouseUp	 (WPARAM buttonState, int x, int y);
	void OnMouseMove (WPARAM buttonState, int x, int y);
	void OnMouseWheel(float wheelDelta,   int x, int y);
private:
	/*
	Mesh* meshOne;
	Mesh* meshTwo;
	Mesh* meshThree;
	Entity* entityOne;
	Entity* entityTwo;
	Entity* entityThree;
	*/
	Entity* cube;
	Entity* helix;
	Mesh* cubeMesh;
	Mesh* helixMesh;
	Camera* camera;
	Material* material;
	Material* materialTwo;
	float timer;
	DirectionalLight light;
	DirectionalLight lightTwo;


	// Initialization helper methods - feel free to customize, combine, etc.
	void LoadShaders(); 
	void CreateMatrices();
	void CreateBasicGeometry();

	// Buffers to hold actual geometry data

	// Wrappers for DirectX shaders to provide simplified functionality
	SimpleVertexShader* vertexShader;
	SimplePixelShader* pixelShader;

	// The matrices to go from model space to screen space
	DirectX::XMFLOAT4X4 worldMatrix;
	DirectX::XMFLOAT4X4 viewMatrix;
	DirectX::XMFLOAT4X4 projectionMatrix;

	// Keeps track of the old mouse position.  Useful for 
	// determining how far the mouse moved in a single frame.
	POINT prevMousePos;
};

