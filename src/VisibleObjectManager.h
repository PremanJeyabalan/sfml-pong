#pragma once
#ifndef PONG_VISIBLE_OBJECT_MANAGER_H
#define PONG_VISIBLE_OBJECT_MANAGER_H

#include "VisibleObject.h"
#include "SFML/Graphics.hpp"
#include <unordered_map>

class VisibleObjectManager {
public:
	~VisibleObjectManager();
	void add(std::string&& name, VisibleObject* object);
	void remove(std::string&& name);
	VisibleObject* get(std::string&& name);

	void handleInputAll(sf::Event* event);
	void updateAll(float timeElapsed);
	void updateAllDP(float timeElapsed);
	void drawAll(sf::RenderWindow* window);

private:
	std::unordered_map<std::string, VisibleObject*> _objects;
	//static float total_seconds;
	//static int total_count;
};
#endif // !PONG_VISIBLE_OBJECT_MANAGER_H



