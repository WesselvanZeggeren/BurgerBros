#include "GameObject.h"
#include "ModelComponent.h"
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>

GameObject::GameObject()
{
}

GameObject::~GameObject()
{
}

void GameObject::addComponent(Component* component)
{
	
	component->setGameObject(this);
	components.push_back(component);
	
	if (!modelComponent)
		modelComponent = dynamic_cast<ModelComponent*>(component);
}

void GameObject::replaceComponent(Component* component, bool attach)
{

	attached = attach;

	components.clear();
	modelComponent = dynamic_cast<ModelComponent*>(component);

	addComponent(component);
}

std::list<Component*> GameObject::getComponents()
{
	
	return components;
}


void GameObject::draw(const glm::mat4& parentMatrix)
{

	if (!modelComponent)
		return;

	glm::mat4 modelMatrix = parentMatrix;
	modelMatrix = glm::translate(modelMatrix, position);
	modelMatrix = glm::rotate(modelMatrix, rotation.x, glm::vec3(1, 0, 0));
	modelMatrix = glm::rotate(modelMatrix, rotation.y, glm::vec3(0, 1, 0));
	modelMatrix = glm::rotate(modelMatrix, rotation.z, glm::vec3(0, 0, 1));
	modelMatrix = glm::scale(modelMatrix, scale);

	tigl::shader->setModelMatrix(modelMatrix);
	modelComponent->draw();
}

void GameObject::update(float elapsedTime)
{

	for (auto& c : components)
		c->update(elapsedTime);
}

void GameObject::setAttached(bool attach)
{
	attached = attach;
}