#include "Pong.h"

sf::RenderWindow Pong::_window;
sf::Clock Pong::_clock;
Pong::State Pong::_state = Uninitialized;
std::map<Pong::State, GameState*> Pong::_stateInstances;

void Pong::start() {
	//if the window is already open, don't do anything
	if (_state != Uninitialized) return;

	_window.create(sf::VideoMode(Pong::SCREEN_WIDTH, Pong::SCREEN_HEIGHT, 32), "Pong");
	_window.setFramerateLimit(60);

	_stateInstances[Splashscreen] = new SplashscreenState();
	_stateInstances[Splashscreen]->init();

	_stateInstances[Menu] = new MenuState();
	_stateInstances[Menu]->init();

	_stateInstances[Playing] = new PlayingState();
	_stateInstances[Playing]->init();

	_state = Splashscreen;

	gameLoop();

	auto it = _stateInstances.begin();

	while (it != _stateInstances.end()) {
		delete it->second;
		++it;
	}
	_window.close();
}

void Pong::gameLoop() {

	while (_state != Exiting) {

		//Get the time elapsed since our last loop execution
		float timeElapsed = _clock.restart().asSeconds();

		//Reset out window content
		_window.clear(sf::Color(255, 255, 255));

		//To prevent changing state during a frame
		GameState* currentState = _stateInstances[_state];


		//Handle input
		sf::Event event;
		while (_window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) { _state = Exiting; }
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) { _state = Exiting; }


			
			currentState->handleInput(&event);
		}

		//Update our entities
		currentState->update(timeElapsed);

		//Draw our new entities
		currentState->draw(&_window);
		_window.display();
		currentState->endLoopLogic();
	}
}

void Pong::setState(Pong::State s) { _state = s; }