#pragma once
#ifndef PONG_GAME_STATE_H
#define PONG_GAME_STATE_H
#include <SFML/Graphics.hpp>
#include "../VisibleObjectManager.h"

class GameState {
public:
	virtual ~GameState();
	virtual void init() = 0;
	virtual void handleInput(sf::Event *event) = 0;
	virtual void update(float timeElapsed) = 0;
	virtual void draw(sf::RenderWindow* window) = 0;
	virtual void endLoopLogic() {};
	VisibleObjectManager* getObjectManager();
	enum PlayingType { Singleplayer, Multiplayer };

protected:
	VisibleObjectManager _visibleObjectManager;
};

#endif