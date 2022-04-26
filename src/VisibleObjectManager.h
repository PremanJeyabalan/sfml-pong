#pragma once
#ifndef PONG_VISIBLE_OBJECT_MANAGER_H
#define PONG_VISIBLE_OBJECT_MANAGER_H

#include "VisibleObject.h"
#include "SFML/Graphics.hpp"

class VisibleObjectManager {
public:
	~VisibleObjectManager();
	void add(std::string&& name, VisibleObject* object);
	void remove(std::string&& name);
	VisibleObject* get(std::string&& name);

	void handleInputAll(sf::Event* event);
	void updateAll(float timeElapsed);
	void drawAll(sf::RenderWindow* window);

private:
	std::map<std::string, VisibleObject*> _objects;
};
#endif // !PONG_VISIBLE_OBJECT_MANAGER_H



