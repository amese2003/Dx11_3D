#pragma once

struct ModelBone
{
	wstring name; 
	int32 index;	
	int32 parentIndex;
	shared_ptr<ModelBone> parent;

	Matrix transform;
	vector<shared_ptr<ModelBone>> children;
};