#include "pch.h"
#include "11. DepthStencilBuffer.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "GameObject.h"
#include "CameraScript.h"
#include "MeshRenderer.h"
#include "Mesh.h"

void DepthStencilDemo::Init()
{
	_shader = make_shared<Shader>(L"08. GlobalDemo.fx");

	// Camera
	_camera = make_shared<GameObject>();
	_camera->GetOrAddTransform();
	_camera->AddComponent(make_shared<Camera>());
	_camera->AddComponent(make_shared<CameraScript>());

	// Object
	_obj = make_shared<GameObject>();
	_obj->GetOrAddTransform();
	_obj->AddComponent(make_shared<MeshRenderer>());
	{
		_obj->GetMeshRenderer()->SetShader(_shader);
	}
	{
		RESOURCES->Init();
		auto mesh = RESOURCES->Get<Mesh>(L"Sphere");
		_obj->GetMeshRenderer()->SetMesh(mesh);
	}
	{
		auto texture = RESOURCES->Load<Texture>(L"Hoshino", L"..\\Resources\\Texture\\hoshino.png");
		_obj->GetMeshRenderer()->SetTexture(texture);
	}

	_obj2 = make_shared<GameObject>();
	_obj2->GetOrAddTransform()->SetPosition(Vec3(0.5f, 0.f, 2.f));
	_obj2->AddComponent(make_shared<MeshRenderer>());
	{
		_obj2->GetMeshRenderer()->SetShader(_shader);
	}
	{
		auto mesh = RESOURCES->Get<Mesh>(L"Cube");
		_obj2->GetMeshRenderer()->SetMesh(mesh);
	}
	{
		auto texture = RESOURCES->Load<Texture>(L"Hoshino", L"..\\Resources\\Texture\\hoshino.png");
		_obj2->GetMeshRenderer()->SetTexture(texture);
	}


	RENDER->Init(_shader);
}

void DepthStencilDemo::Update()
{
	_camera->Update();
	RENDER->Update();

	
	_obj->Update();
	_obj2->Update();
}

void DepthStencilDemo::Render()
{

}
