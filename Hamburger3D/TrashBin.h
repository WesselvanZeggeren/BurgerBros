#pragma once
#include "GameObject.h"
class TrashBin : public GameObject
{
private:
	std::list<GameObject*> parts;

};

