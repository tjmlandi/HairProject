#include "Camera.h"

using namespace DirectX;

Camera::Camera()
{
	rotationX = 0.0f;
	roationY = 0.0f;
	this->position = XMFLOAT3(0.0f, 0.0f, -5.0f);
	XMMATRIX V = XMMatrixLookToLH(XMLoadFloat3(&this->position), XMVectorSet(rotationX, roationY, +1.0f, +0.0f), XMVectorSet(0.0f, 1.0f, 0.0f, 1.0f));
	viewMatrix = XMMatrixTranspose(V);
	isRotating = false;
}


Camera::~Camera()
{
} 

void Camera::Update(float deltaTime)
{
	if (GetAsyncKeyState('W') & 0x8000) { 
		this->position.z += 2 * deltaTime;
	}
	if (GetAsyncKeyState('S') & 0x8000) {
		this->position.z -= 2 * deltaTime;
	}
	if (GetAsyncKeyState('A') & 0x8000) {
		this->position.x -= 2 * deltaTime;
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		this->position.x += 2 * deltaTime;
	}
	if (GetAsyncKeyState('D') & 0x8000) {
		this->position.x += 2 * deltaTime;
	}
	if (GetAsyncKeyState(VK_LSHIFT) & 0x8000) {
		this->position.y -= 2 * deltaTime;
	}
	if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
		this->position.y += 2 * deltaTime;
	}
	viewMatrix = XMMatrixTranspose(XMMatrixLookToLH(XMLoadFloat3(&this->position), XMVectorSet(rotationX, roationY, +1.0f, +0.0f), XMVectorSet(0.0f,1.0f,0.0f,1.0f)));
	
}

XMFLOAT4X4 Camera::getViewMatrix()
{
	XMFLOAT4X4 toReturn;
	XMStoreFloat4x4(&toReturn, this->viewMatrix);
	return toReturn;
}

void Camera::rotateX(float x)
{
	this->rotationX += x;
}

void Camera::rotateY(float y)
{
	this->roationY += y;
}

void Camera::toggleRotationOff()
{
	this->isRotating = false;
}

void Camera::toggleRotationOn()
{
	this->isRotating = true;
}

bool Camera::isCamRotating()
{
	return this->isRotating;
}

void Camera::createProjectionMatrix(int width, int height)
{
	XMMATRIX P = XMMatrixPerspectiveFovLH(
		0.25f * 3.1415926535f,		// Field of View Angle
		(float)width / height,		// Aspect ratio
		0.1f,						// Near clip plane distance
		100.0f);					// Far clip plane distance
	XMStoreFloat4x4(&projectionMatrix, XMMatrixTranspose(P));
}

XMFLOAT4X4 Camera::getProjectionMatrix()
{
	return this->projectionMatrix;
}
