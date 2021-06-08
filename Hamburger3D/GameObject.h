#pragma once

#include <list>
#include <glm/glm.hpp>

class Component;
class ModelComponent;

class GameObject
{
	
	ModelComponent* modelComponent = nullptr;

	std::list<Component*> components;

public:
	GameObject();
	~GameObject();

	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale = glm::vec3(1, 1, 1);

	bool attached = false;
	bool grabbable = true;

	void addComponent(Component* component);
	void replaceComponent(Component* component, bool attach);

	std::list<Component*> getComponents();

	void update(float elapsedTime);
	void draw(const glm::mat4 & = glm::mat4(1.0f));
	void setAttached(bool attach);

	template<class T>
	T* getComponent()
	{
		for (auto c : components)
		{
			T* t = dynamic_cast<T*>(c);
			if (t)
				return t;
		}
		return nullptr;
	}

	template<class T>
	void removeComponent()
	{
		components.remove_if([](Component* c)
		{
			T* t = dynamic_cast<T*>(c);
			return t != nullptr;
		});
	}
};