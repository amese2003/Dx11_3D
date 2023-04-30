#pragma once
#include "Component.h"

struct VertexBillboard
{
	Vec3 position;
	Vec2 uv;
	Vec2 scale;
};

#define MAX_BILLBOARD_COUNT 500

class BillBoard : public Component
{
	using Super = Component;

public:
	BillBoard();
	~BillBoard();

	void Update();
	void Add(Vec3 position, Vec2 scale);

	void SetMaterial(shared_ptr<Material> material) { _material = material; }
	void SetPass(uint8 pass) { _pass = pass; }

private:
	vector<VertexBillboard> _vertices;
	vector<uint32> _indices;
	shared_ptr<VertexBuffer> _vertexBuffer;
	shared_ptr<IndexBuffer> _indexBuffer;

	shared_ptr<Material> _material;
	
	int32 _drawCount = 0;
	int32 _prevCount = 0;

	uint8 _pass = 0;
};

