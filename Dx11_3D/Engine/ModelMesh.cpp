#include "pch.h"
#include "ModelMesh.h"

void ModelMesh::Update()
{

}

void ModelMesh::CreateBuffers()
{
	vertexBuffer = make_shared<VertexBuffer>();
	vertexBuffer->Create(geometry->GetVertices());
	indexBuffer = make_shared<IndexBuffer>();
	indexBuffer->Create(geometry->GetIndices());
}