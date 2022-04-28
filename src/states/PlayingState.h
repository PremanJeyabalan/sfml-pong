#pragma once
#ifndef PONG_PLAYING_STATE_H
#define PONG_PLAYING_STATE_H

#include "GameState.h"
#include "../objects/entities/Field.h"
#include "../objects/entities/Paddle.h"
#include "../objects/entities/Ball.h"

class PlayingState : public GameState {
public:
	PlayingState(PlayingType gameType);
	virtual void init();
	void gameInit();
	void handleInput(sf::Event* event) override;
	void update(float timeElapsed) override;
	void draw(sf::RenderWindow* window) override;
	void endLoopLogic() override;
	void reset();
	

private:
	PlayingType _gameType;
	int _scorePlayer1 = 0;
	int _scorePlayer2 = 0;
	bool _isDone;
	sf::Font _scoreFont;
	sf::Text _scoreText;
	sf::Text _endGameText;
};

#endif

