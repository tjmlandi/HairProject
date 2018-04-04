#include "Entity.h"


using namespace DirectX;

Entity::Entity(Mesh * newMesh, Material* newMaterial)
{
	this->objectMesh = newMesh;
	XMStoreFloat4x4(&this->worldMatrix, XMMatrixIdentity());
	this->position = XMFLOAT3(+0.0f, +0.0f, +0.0f);
	this->rotation = XMFLOAT3(+0.0f, +0.0f, +0.0f);
	this->scale = XMFLOAT3(+1.0f, +1.0f, +1.0f);
	this->hasMatrixChanged = true;
	this->material = newMaterial;
}

Entity::~Entity()
{
}

void Entity::updateMatrix()
{
	if (hasMatrixChanged) {
		XMStoreFloat4x4(&this->worldMatrix, 
						XMMatrixTranspose(XMMatrixMultiply(XMMatrixTranslation(this->position.x, this->position.y, this->position.z),
										 XMMatrixMultiply(
											XMMatrixScaling(this->scale.x, this->scale.y, this->scale.z),
											XMMatrixRotationQuaternion(XMLoadFloat3(&this->rotation))))));
		hasMatrixChanged = false;
	}
}

void Entity::prepareMaterials(XMFLOAT4X4 view, XMFLOAT4X4 projection)
{
	// Set the vertex and pixel shaders to use for the next Draw() command
	//  - These don't technically need to be set every frame...YET
	//  - Once you start applying different shaders to different objects,
	//    you'll need to swap the current shaders before each draw
	this->material->getVertexShader()->SetShader();
	this->material->getPixelShader()->SetShader();

	// Send data to shader variables
	//  - Do this ONCE PER OBJECT you're drawing
	//  - This is actually a complex process of copying data to a local buffer
	//    and then copying that entire buffer to the GPU.  
	//  - The "SimpleShader" class handles all of that for you.
	this->material->getVertexShader()->SetMatrix4x4("world", this->worldMatrix);
	this->material->getVertexShader()->SetMatrix4x4("view", view);
	this->material->getVertexShader()->SetMatrix4x4("projection", projection);


	// Once you've set all of the data you care to change for
	// the next draw call, you need to actually send it to the GPU
	//  - If you skip this, the "SetMatrix" calls above won't make it to the GPU!
	this->material->getVertexShader()->CopyAllBufferData();

}

void Entity::setPosition(XMFLOAT3 newPosition)
{
	this->position = newPosition;
	hasMatrixChanged = true;
}

void Entity::setRotation(XMFLOAT3 newRotation)
{
	this->rotation = newRotation;
	hasMatrixChanged = true;
}

void Entity::setScale(XMFLOAT3 newScale)
{
	this->scale = newScale;
	hasMatrixChanged = true;
}

XMFLOAT3 Entity::getPosition()
{
	return this->position;
}

XMFLOAT3 Entity::getRotation()
{
	return this->rotation;
}

XMFLOAT3 Entity::getScale()
{
	return this->scale;
}

XMFLOAT4X4 Entity::getWorldMatrix()
{
	return this->worldMatrix;
}

Mesh * Entity::getMesh()
{
	return this->objectMesh;
}
