#include "pch.h"
#include "Camera.h"
#include "05. TextureDemo.h"
#include "CameraScript.h"

void TextureDemo::Init()
{
	_shader = make_shared<Shader>(L"04. Texture.fx");

	_geometry = make_shared<Geometry<VertexTextureData>>();
	GeometryHelper::CreateGrid(_geometry, 10, 10);

	_vertexBuffer = make_shared<VertexBuffer>();
	_vertexBuffer->Create(_geometry->GetVertices());

	_indexBuffer = make_shared<IndexBuffer>();
	_indexBuffer->Create(_geometry->GetIndices());

	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform();
	_camera->GetTransform()->SetPosition(Vec3(0, 1, -5));
	//_camera->GetTransform()->SetRotation(Vec3(0, 10, 0));
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());

	_texture = RESOURCES->Load<Texture>(L"Hoshino", L"..\\Resources\\Texture\\Hoshino.png");
}

void TextureDemo::Update()
{
	_camera->Update();
}

void TextureDemo::Render()
{
	_shader->GetMatrix("World")->SetMatrix((float*)&_world);
	_shader->GetMatrix("View")->SetMatrix((float*)&Camera::S_MatView);
	_shader->GetMatrix("Projection")->SetMatrix((float*)&Camera::S_MatProjection);
	_shader->GetSRV("Texture0")->SetResource(_texture->GetComPtr().Get());
	
	

	uint32 stride = _vertexBuffer->GetStride();
	uint32 offset = _vertexBuffer->GetOffset();

	DC->IASetVertexBuffers(0, 1, _vertexBuffer->GetComPtr().GetAddressOf(), &stride, &offset);
	DC->IASetIndexBuffer(_indexBuffer->GetComPtr().Get(), DXGI_FORMAT_R32_UINT, 0);
	
	_shader->DrawIndexed(0, 1, _indexBuffer->GetCount(), 0, 0);
}
