#pragma once
#include "Component.h"

struct VertexSnow
{
	Vec3 position;
	Vec2 uv;
	Vec2 scale;
	Vec2 random;
};

#define MAX_BILLBOARD_COUNT 500

class SnowBillBoard : public Component
{
	using Super = Component;

public:
	SnowBillBoard(Vec3 extend, int32 drawCount = 100);
	~SnowBillBoard();

	void Update();

	void SetMaterial(shared_ptr<Material> material) { _material = material; }
	void SetPass(uint8 pass) { _pass = pass; }

private:
	vector<VertexSnow> _vertices;
	vector<uint32> _indices;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	int32 _drawCount = 0;

	shared_ptr<Material> _material;
	uint8 _pass = 0;

	SnowBillboardDesc _desc;
	float _elpasedTime = 0.f;
};

