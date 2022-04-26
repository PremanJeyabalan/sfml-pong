#include "Ball.h"
#include <iostream>

Ball::Ball(sf::Rect<float>&& constraints) : VisibleObject("assets/ball.png"), _speed(500.0f), _angle(rand() % 2 == 0 ? 0 : 180), _constraints(constraints), isOut(false) {}

void Ball::update(float timeElpased) {
	if (isOut) return;

	float velocity = _speed * timeElpased;
	float angleInRadian = _angle * M_PI / 180.0f;

	float velocityX = velocity * std::cos(angleInRadian);
	float velocityY = velocity * std::sin(angleInRadian);

	//Handle bounce with the top and bottom walls
	if (getTop() + velocityY <= _constraints.top || getBottom() + velocityY >= _constraints.top + _constraints.height) {
		_angle = 360 - _angle;
		velocityY *= -1;
	}

	//Temporarily handle bounce with the side walls
	if (getLeft() + velocityX <= _constraints.left || getRight() + velocityX >= _constraints.left + _constraints.width) {
		isOut = true;
	}

	move(velocityX, velocityY);
}

void Ball::collideWith(VisibleObject* target) {
	if (isOut) return;
	if (!dynamic_cast<Paddle*>(target)) return;

	float paddleCenterY = (target->getTop() + target->getBottom()) / 2;
	float ballCenterY = (getTop() + getBottom()) / 2;

	float distDiff = ballCenterY - paddleCenterY;
	float maxDiff = target->getBoundingRect().height;

	float normalizedDiff = distDiff / maxDiff;

	_angle = (int)(normalizedDiff * 80);

	if (target->getPosition().x < Pong::SCREEN_WIDTH / 2) {
		_angle = (int)(normalizedDiff * 90);
	}
	else {
		_angle = 180 - (int)(normalizedDiff * 90);
	}

	_speed += 100;

	if (_speed > _maxSpeed)
		_speed = _maxSpeed;

}
