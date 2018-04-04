#pragma once

#include <DirectXMath.h>
#include "Mesh.h"

using namespace DirectX;


class Camera
{
	XMFLOAT4X4 projectionMatrix;
	XMMATRIX viewMatrix;
	XMFLOAT3 position;
	bool isRotating;
	float rotationX;
	float roationY;

public:
	Camera();
	~Camera();
	void Update(float deltaTime);
	XMFLOAT4X4 getViewMatrix();
	void rotateX(float x);
	void rotateY(float y);
	void toggleRotationOff();
	void toggleRotationOn();
	bool isCamRotating();
	void createProjectionMatrix(int width, int height);
	XMFLOAT4X4 getProjectionMatrix();

};

