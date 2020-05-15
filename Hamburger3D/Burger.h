#pragma once

#include <list>
#include "BaconModelComponent.h"
#include "BunCorwnModelComponent.h"
#include "BunHeelModelComponent.h"
#include "CheeseModelComponent.h"
#include "CubeModelComponent.h"
#include "EggModelComponent.h"
#include "LetaceModelComponent.h"
#include "PattyModelComponent.h"
#include "PickleModelComponent.h"
#include "SouceModelComponent.h"
#include "TomatoModelComponent.h"
#include "UnionModelComponent.h"

class Burger {
private:

	std::list<GameObject*> ingredients;

public:
	Burger();
	~Burger();



};