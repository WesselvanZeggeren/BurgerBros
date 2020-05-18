#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include "basicShapeDrawer.h"
#include "BurgerDrawer.h"
#include <glm/gtc/matrix_transform.hpp>

namespace bdm 
{

	void completeBurger(glm::mat4 model);

	void burgerBunCrown(glm::mat4 model);
	void burgerBunHeel(glm::mat4 model);

	void burgerPatty(glm::mat4 model);

	void tomato(glm::mat4 model);
	void cheese(glm::mat4 model, int type);

	void letace(glm::mat4 model);
	void souce(glm::mat4 model, int type);
	void dicedUnions(glm::mat4 model);
	void pickle(glm::mat4 model);
	void bacon(glm::mat4 model);
	void egg(glm::mat4 model);
}