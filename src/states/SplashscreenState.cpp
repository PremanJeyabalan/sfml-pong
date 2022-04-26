#include "SplashscreenState.h"


void SplashscreenState::init() {
	if (!_texture.loadFromFile("assets/splashscreen.png")) {
		std::cout << "Error while loading assets" << std::endl;
		return;
	}
	_sprite.setTexture(_texture);
}

void SplashscreenState::handleInput(sf::Event* event) {
	if (event->type == sf::Event::EventType::KeyPressed
		|| event->type == sf::Event::EventType::MouseButtonPressed) {
		Pong::setState(Pong::Menu);
	}
}

void SplashscreenState::update(float timeElapsed) {

}

void SplashscreenState::draw(sf::RenderWindow* window) {
	window->draw(_sprite);
}


