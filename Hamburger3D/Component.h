#pragma once

class GameObject;

class Component
{

public:
	GameObject* gameObject;

	Component();
	~Component();

	virtual void update(float elapsedTime) {};

	inline void setGameObject(GameObject* gameObject) { this->gameObject = gameObject;}
};

