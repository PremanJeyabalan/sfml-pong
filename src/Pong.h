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
	const static sf::VideoMode desktop;
	const static int SCREEN_WIDTH;
	const static int SCREEN_HEIGHT;
	static GameState* getState();
	static GameState* _currentState;
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
