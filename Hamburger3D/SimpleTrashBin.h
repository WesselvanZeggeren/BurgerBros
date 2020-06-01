#pragma once
#include "ModelComponent.h"
class SimpleTrashBin : public ModelComponent
{
public:
	SimpleTrashBin();
	~SimpleTrashBin();

	virtual void draw() override;
	void setSauseType(int type);
};

