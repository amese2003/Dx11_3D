#pragma once
#include "Component.h"

class Model;

// [frame][bone]
struct AnimTransform
{
	// [ ][ ][ ][ ][ ] ... 250°³
	using TransformArrayType = array<Matrix, MAX_MODEL_TRANSFORMS>;
	// [ ][ ][ ][ ][ ] ... 500°³
	array<TransformArrayType, MAX_MODEL_KEYFRAMES> transforms;
};

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
	void CreateTexture();
	void CreateAnimationTransform(uint32 index);

private:
	void Update();

private:
	vector<AnimTransform> _animTransforms;
	ComPtr<ID3D11Texture2D> _texture;
	ComPtr<ID3D11ShaderResourceView> _srv;

private:
	KeyframeDesc _keyframeDesc;
	TweenDesc _tweenDesc;

private:
	shared_ptr<Shader> _shader;
	uint8				_pass = 0;
	shared_ptr<Model> _model;

};

