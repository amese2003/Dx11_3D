#pragma once
#include "Component.h"

class Model;

class ModelAnimator : public Component
{
	using Super = Component;

public:
	ModelAnimator(shared_ptr<Shader> shader);
	~ModelAnimator();

public:
	void SetModel(shared_ptr<Model> model);
	void SetPass(uint32 pass) { _pass = pass; }

private:
	void Update();

	

private:
	shared_ptr<Shader> _shader;
	uint8				_pass = 0;
	shared_ptr<Model> _model;

};

