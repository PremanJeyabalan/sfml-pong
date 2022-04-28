#ifndef PONG_PADDLE_H
#define PONG_PADDLE_H

#include "../../VisibleObject.h"
#include "./Ball.h"
#include "../../Pong.h"

class Paddle : public VisibleObject {
public:
	Paddle(float constraintTop, float constraintBottom, bool isAI, bool isLeft);
	void handleInput(sf::Event* event);
	void update(float timeElapsed);
	void runAI(); //to seperate AI logic
	const bool _isAI;

private:
	enum Direction { DIRECTION_NONE, DIRECTION_UP, DIRECTION_DOWN };
	sf::Keyboard::Key UP_KEY;
	sf::Keyboard::Key DOWN_KEY;
	Direction _direction = DIRECTION_NONE;
	float _speed = 800.0f;
	float _constraintTop;
	float _constraintBottom;
};

#endif // !PONG_PADDLE_H

