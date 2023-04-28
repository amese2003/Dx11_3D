#include "pch.h"
#include "OrthographicDemo.h"
#include "GeometryHelper.h"
#include "Camera.h"
#include "GameObject.h"
#include "CameraScript.h"
#include "MeshRenderer.h"
#include "Mesh.h"
#include "Material.h"
#include "Model.h"
#include "ModelRenderer.h"
#include "ModelAnimator.h"
#include "Mesh.h"
#include "Transform.h"
#include "VertexBuffer.h"
#include "IndexBuffer.h"
#include "Light.h"
#include "TextureBuffer.h"
#include "Viewport.h"
#include "SphereCollider.h"
#include "Scene.h"
#include "AABBBoxCollider.h"
#include "OBBBoxCollider.h"
#include "Terrain.h"

void OrthographicDemo::Init()
{

	_shader = make_shared<Shader>(L"23. RenderDemo.fx");

	// Camera
	{
		auto camera = make_shared<GameObject>();
		camera->GetOrAddTransform()->SetPosition(Vec3{ 0.f, 0.f, -5.f });
		camera->AddComponent(make_shared<Camera>());
		camera->AddComponent(make_shared<CameraScript>());
		CUR_SCENE->Add(camera);
	}


	{
		auto camera = make_shared<GameObject>();
		camera->GetOrAddTransform()->SetPosition(Vec3{ 0.f, 0.f, -5.f });
		camera->AddComponent(make_shared<Camera>());
		//camera->GetCamera()->SetProjectionType(ProjectionType::Orthographic);
		camera->GetCamera()->SetNear(1.f);
		camera->GetCamera()->SetFar(100.f);

		//camera->GetCamera()->SetCullingMaskAll();
		//camera->GetCamera()->SetCullingMaskLayerOnOff!;
	}

	// Light
	{
		auto light = make_shared<GameObject>();
		light->AddComponent(make_shared<Light>());
		LightDesc lightDesc;
		lightDesc.ambient = Vec4(0.4f);
		lightDesc.diffuse = Vec4(1.f);
		lightDesc.specular = Vec4(0.1f);
		lightDesc.direction = Vec3(1.f, 0.f, 1.f);
		light->GetLight()->SetLightDesc(lightDesc);
		CUR_SCENE->Add(light);
	}

	
	// ÁöÇü
	{
		auto obj = make_shared<GameObject>();
		obj->AddComponent(make_shared<Terrain>());
		obj->GetTerrain()->Create(10, 10, RESOURCES->Get<Material>(L"Hoshino"));

		CUR_SCENE->Add(obj);
	}

	{
		auto obj = make_shared<GameObject>();
		//obj->GetOrAddTransform()->SetLocalPosition(Vec3(rand() % 100, 0, rand() % 100));
		obj->GetOrAddTransform()->SetLocalPosition(Vec3(0.f));
		obj->AddComponent(make_shared<MeshRenderer>());
		{
			obj->GetMeshRenderer()->SetMaterial(RESOURCES->Get<Material>(L"Hoshino"));
		}
		{
			auto mesh = RESOURCES->Get<Mesh>(L"Cube");
			obj->GetMeshRenderer()->SetMesh(mesh);
			obj->GetMeshRenderer()->SetPass(0);
		}

		{
			auto collider = make_shared<AABBBoxCollider>();
			collider->GetBoundingBox().Extents = Vec3(0.5f);
			obj->AddComponent(collider);
		}

		/*{
			obj->GetOrAddTransform()->SetRotation(Vec3(0, 45, 0));


			auto collider = make_shared<OBBBoxCollider>();
			collider->GetBoundingBox().Extents = Vec3(0.5f);
			collider->GetBoundingBox().Orientation = Quaternion::CreateFromYawPitchRoll(45, 0, 0);
;			obj->AddComponent(collider);
		}*/

		CUR_SCENE->Add(obj);
	}

	//RENDER->Init(_shader);
}

void OrthographicDemo::Update()
{
	if (INPUT->GetButtonDown(KEY_TYPE::LBUTTON))
	{
		int32 mouseX = INPUT->GetMousePos().x;
		int32 mouseY = INPUT->GetMousePos().y;

		// Pick?
		auto pickObj = CUR_SCENE->Pick(mouseX, mouseY);

		if (pickObj)
		{
			CUR_SCENE->Remove(pickObj);
		}
	}

}

void OrthographicDemo::Render()
{

}
