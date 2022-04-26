#pragma once
#ifndef PONG_PLAYING_STATE_H
#define PONG_PLAYING_STATE_H

#include "GameState.h"
#include "../objects//entities/Field.h"
#include "../objects//entities/Paddle.h"
#include "../objects/entities/Ball.h"
#include <iostream>

class PlayingState : public GameState {
public:
	void init() override;
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;

};

#endif

