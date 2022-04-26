#pragma once
#ifndef PONG_SPLASHSCREEN_STATE_H
#define PONG_SPLASHSCREEN_STATE_H

#include "GameState.h"
#include <iostream>
#include "../Pong.h"

class SplashscreenState : public GameState {
public:
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;

private:
	sf::Texture _texture;
	sf::Sprite _sprite;
};

#endif // !PONG_SPLASHSCREEN_STATE_H
