#include "Paddle.h"

Paddle::Paddle(float constraintTop, float constraintBottom, bool isAI, bool isLeft) : VisibleObject("assets/paddle.png"), _constraintBottom(constraintBottom), _constraintTop(constraintTop), _isAI(isAI) {
	//To prevent recalculation of fieldBound on each turn as it never changes
	if (isLeft) { 
		UP_KEY = sf::Keyboard::W;
		DOWN_KEY = sf::Keyboard::S;
	}
	else {
		UP_KEY = sf::Keyboard::Up;
		DOWN_KEY = sf::Keyboard::Down;
	}
}

void Paddle::handleInput(sf::Event* event) {
	if (_isAI) return;

	if (event->type == sf::Event::KeyPressed) {
		if (event->key.code == UP_KEY)
			_direction = DIRECTION_UP;
		else if (event->key.code == DOWN_KEY)
			_direction = DIRECTION_DOWN;
	}
	else if (event->type == sf::Event::KeyReleased)
		_direction = DIRECTION_NONE;
}

void Paddle::update(float timeElapsed) {
	runAI();

	float velocity = 0.0f;
	if (_direction == DIRECTION_UP)
		velocity = _speed * -1;
	else if (_direction == DIRECTION_DOWN)
		velocity = _speed;

	move(0, velocity * timeElapsed);

	const sf::Vector2<float> pos = getPosition();

	if (pos.y < _constraintTop)
		setPosition(pos.x, _constraintTop);
	else if (pos.y + getBoundingRect().height > _constraintBottom)
		setPosition(pos.x, _constraintBottom - getBoundingRect().height);
}

void Paddle::runAI() {
	if (!_isAI) return;

	Ball* ball = dynamic_cast<Ball*>(Pong::getState()->getObjectManager()->get("ball"));

	if (ball->getBottom() > getBottom())
		_direction = DIRECTION_DOWN;
	else if (ball->getTop() > getTop())
		_direction = DIRECTION_UP;
	else
		_direction = DIRECTION_NONE;

}