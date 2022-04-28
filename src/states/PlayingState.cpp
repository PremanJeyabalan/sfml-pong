#include "PlayingState.h"

void PlayingState::init() {
	Field* field = new Field();
	field->setPosition(50, 25);
	_visibleObjectManager.add("field", field);

	Paddle* player1 = new Paddle(field->getTop() + 10, field->getBottom() - 10, false, true);
	_visibleObjectManager.add("player1", player1);

	Paddle* player2 = new Paddle(field->getTop() + 10, field->getBottom() - 10, false, false);
	_visibleObjectManager.add("player2", player2);

	//Score
	if (!_scoreFont.loadFromFile("assets/fonts/Roboto-Bold.ttf")) {
		std::cout << "error while loading Roboto font" << std::endl;
	}

	_scoreText.setFont(_scoreFont);
	_scoreText.setCharacterSize(100);
	_scoreText.setStyle(sf::Text::Bold);
	_scoreText.setFillColor(sf::Color::Black);
	_scoreText.setString("0 - 0");

	auto bound = _scoreText.getGlobalBounds();
	_scoreText.setPosition(Pong::SCREEN_WIDTH / 2 - bound.width / 2, 50);

	_isDone = false;
	_endGameText.setFont(_scoreFont);
	_endGameText.setCharacterSize(150);
	_endGameText.setStyle(sf::Text::Bold);
	_endGameText.setFillColor(sf::Color::Black);

	reset();
}

void PlayingState::reset() {
	Field* field = dynamic_cast<Field*>(_visibleObjectManager.get("field"));
	//Objects positions
	Paddle* player1 = dynamic_cast<Paddle*>(_visibleObjectManager.get("player1"));
	player1->setPosition(field->getLeft() + 20, Pong::SCREEN_HEIGHT / 2);

	Paddle* player2 = dynamic_cast<Paddle*>(_visibleObjectManager.get("player2"));
	player2->setPosition(field->getRight() - 40, Pong::SCREEN_HEIGHT / 2);

	//Reset ball
	_visibleObjectManager.remove("ball");

	Ball* ball = new Ball(
		sf::Rect<float>(field->getLeft() + 10, field->getTop() + 10, field->getBoundingRect().width - 20, field->getBoundingRect().height - 20)
	);

	float centerX = field->getLeft() + field->getBoundingRect().width / 2;
	float centerY = field->getTop() + field->getBoundingRect().height / 2;
	const sf::Rect<float> ballRect = ball->getBoundingRect();
	ball->setPosition(centerX - ballRect.width / 2, centerY - ballRect.height / 2);
	_visibleObjectManager.add("ball", ball);

	//Scoring
	_scorePlayer1 = 0;
	_scorePlayer2 = 0;
	_scoreText.setString("0 - 0");
	auto bound = _scoreText.getGlobalBounds();
	_scoreText.setPosition(Pong::SCREEN_WIDTH / 2 - bound.width / 2, 50);

	//Game status
	_endGameText.setString("");
	_isDone = false;
}

void PlayingState::handleInput(sf::Event* event) {
	//handle return to main menu when game is over
	if (_isDone) {
		if (event->type == sf::Event::KeyPressed || event->type == sf::Event::MouseButtonPressed) {
			Pong::setState(Pong::Menu);
			reset();
		}
		return;
	}

	_visibleObjectManager.handleInputAll(event);
}

void PlayingState::update(const float timeElapsed) {
	if (_isDone) return;

	_visibleObjectManager.updateAll(timeElapsed);
}

void PlayingState::draw(sf::RenderWindow* window) {
	_visibleObjectManager.drawAll(window);
	window->draw(_scoreText);

	if (_isDone) window->draw(_endGameText);
}

void PlayingState::endLoopLogic() {
	Ball* ball = dynamic_cast<Ball*>(_visibleObjectManager.get("ball"));

	if (ball == nullptr) return;

	if (ball->isOut) {
		//update the score
		auto ballPosition = ball->getPosition();
		ballPosition.x > Pong::SCREEN_WIDTH / 2 ? _scorePlayer1++ : _scorePlayer2++;
		_scoreText.setString(std::to_string(_scorePlayer1) + " - " + std::to_string(_scorePlayer2));
			

		_visibleObjectManager.remove("ball");

		//Check if any player won
		if (_scorePlayer1 >= 3 || _scorePlayer2 >= 3) {
			_isDone = true;

			_endGameText.setString(_scorePlayer1 == 3 ? "Player 1 has won" : "Player 2 has won");
			auto bound = _endGameText.getGlobalBounds();
			_endGameText.setPosition(Pong::SCREEN_WIDTH / 2 - bound.width / 2, Pong::SCREEN_HEIGHT / 2 - bound.height / 2);

			return;
		}
		
		//no player won so create new ball
		Field* field = dynamic_cast<Field*>(_visibleObjectManager.get("field"));
		Ball* ball = new Ball(
			sf::Rect<float>(field->getLeft() + 10, field->getTop() + 10, field->getBoundingRect().width - 20, field->getBoundingRect().height - 20)
		);

		float centerX = field->getLeft() + field->getBoundingRect().width / 2;
		float centerY = field->getTop() + field->getBoundingRect().height / 2;

		const auto ballRect = ball->getBoundingRect();
		ball->setPosition(centerX - ballRect.width / 2, centerY - ballRect.height / 2);
		_visibleObjectManager.add("ball", ball);
	}
}
