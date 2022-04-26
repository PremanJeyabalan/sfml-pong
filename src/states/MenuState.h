#pragma once
#ifndef PONG_MENU_STATE_H
#define PONG_MENU_STATE_H

#include "GameState.h"
#include <iostream>
#include "../Pong.h"

class MenuState :public GameState {
public:
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;

private:
	sf::Texture _playTexture;
	sf::Sprite _playSprite;
	sf::Texture _exitTexture;
	sf::Sprite _exitSprite;
};

#endif // !PONG_MENU_STATE_H



