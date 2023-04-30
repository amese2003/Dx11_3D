#pragma once
#include "Component.h"
class Button : public Component
{
	using Super = Component;

public:
	Button();
	~Button();

	bool Picking(POINT screenPos);

	void Create(Vec2 screenPos, Vec2 size, shared_ptr<Material> material);

	void AddOnClickedEvent(function<void(void)> func);
	void InvokeOnClicked();

private:
	function<void(void)> _onclicked;
	RECT _rect;
};

