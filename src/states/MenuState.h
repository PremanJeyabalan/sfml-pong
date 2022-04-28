#pragma once
#ifndef PONG_MENU_STATE_H
#define PONG_MENU_STATE_H

#include "GameState.h"
#include <iostream>
#include "../Pong.h"

#define MAX_MENU_ITEMS 3

class MenuState :public GameState {
public:
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;
	void menuItemInit(int index);
	void setMenuItemActive(int index);
	enum MenuStates {Singleplayer, Multiplayer, Exit};

private:
	int _currentMenuIndex;
	sf::Font _menuFont;
	sf::Text _menuTextItems[MAX_MENU_ITEMS];
	const std::string _menuDisplayStrings[MAX_MENU_ITEMS] = {"Singleplayer", "Multiplayer", "Exit"};
};

#endif // !PONG_MENU_STATE_H



