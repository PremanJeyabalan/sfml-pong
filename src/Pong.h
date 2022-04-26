#pragma once
#ifndef PONG_PONG_H
#define PONG_PONG_H

#include <SFML/Graphics.hpp>
#include "states/GameState.h"
#include "states/MenuState.h"
#include "states/PlayingState.h"
#include "states/SplashscreenState.h"

class Pong {
public:
	const static int SCREEN_WIDTH = 2048;
	const static int SCREEN_HEIGHT = 1536;
	static void start();
	static void gameLoop();
	enum State { Uninitialized, Splashscreen, Menu, Playing, Exiting};
	static void setState(State s);

private:
	static State _state;
	static std::map<State, GameState*> _stateInstances;
	static sf::RenderWindow _window;
	static sf::Clock _clock;
};

#endif // !PONG_PONG_H
