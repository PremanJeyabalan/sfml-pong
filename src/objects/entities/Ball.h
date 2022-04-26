#pragma once
#ifndef PONG_BALL_H


#define _USE_MATH_DEFINES
#define PONG_BALL_H

#include <cmath>
#include "../../VisibleObject.h"
#include "Paddle.h"

class Ball : public VisibleObject {
public:
	Ball(sf::Rect<float>&& constraints);
	void update(float timeElapsed);
	void collideWith(VisibleObject* target);
	bool isOut;

private:
	int _angle;
	float _speed;
	sf::Rect<float> _constraints;
	float _maxSpeed = 1800.0f;
};

#endif // !PONG_BALL_H



