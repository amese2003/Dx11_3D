#pragma once
class Scene
{

public:
	virtual void Start();
	virtual void Update();
	virtual void LateUpdate();

	virtual void Add(shared_ptr<GameObject> object);
	virtual void Remove(shared_ptr<GameObject> object);

private:
	unordered_set<shared_ptr<GameObject>> _objects;
	// 캐시 카메라
	unordered_set<shared_ptr<GameObject>> _cameras;
	// 캐시 라이트
	unordered_set<shared_ptr<GameObject>> _lights;
};

