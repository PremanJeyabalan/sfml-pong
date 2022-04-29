#include "MenuState.h"

void MenuState::menuItemInit(int index) {
	_menuTextItems[index].setFont(_menuFont);
	_menuTextItems[index].setFillColor(index == 0 ? sf::Color::Yellow : sf::Color::White);
	_menuTextItems[index].setString(_menuDisplayStrings[index]);
	_menuTextItems[index].setPosition(sf::Vector2<float>(Pong::SCREEN_WIDTH / 2, Pong::SCREEN_HEIGHT / (MAX_MENU_ITEMS + 1) * (index + 1)) );
}

void MenuState::setMenuItemActive(int index) {
	for (int i = 0; i < MAX_MENU_ITEMS; i++) {
		i == index ? _menuTextItems[i].setFillColor(sf::Color::Yellow) : _menuTextItems[i].setFillColor(sf::Color::White);
	}
}

void MenuState::init() {

	if (!_menuFont.loadFromFile("assets/fonts/Roboto-Bold.ttf")) {
		std::cout << "Error loading font" << std::endl;
	}

	for (int i = 0; i < MAX_MENU_ITEMS; i++) {
		menuItemInit(i);
	}

	_currentMenuIndex = 0;


}

void MenuState::handleInput(sf::Event* event) {
	if (event->type == sf::Event::KeyPressed) {

		if (event->key.code == sf::Keyboard::Up) {
			if (_currentMenuIndex == 0) return;

			setMenuItemActive(--_currentMenuIndex);

		}
		else if (event->key.code == sf::Keyboard::Down) {
			if (_currentMenuIndex == MAX_MENU_ITEMS - 1) return;

			setMenuItemActive(++_currentMenuIndex);

		}
		else if (event->key.code == sf::Keyboard::Enter) {
			if (_currentMenuIndex == MenuState::Exit)
				Pong::setState(Pong::Exiting);
			else if (_currentMenuIndex == MenuStates::Singleplayer)
				Pong::setState(Pong::Singleplayer);
			else if (_currentMenuIndex == MenuStates::Multiplayer)
				Pong::setState(Pong::Multiplayer);

		}
	}
}

void MenuState::update(float timeElapsed) {

}

void MenuState::draw(sf::RenderWindow* window) {
	for (int i = 0; i < MAX_MENU_ITEMS; i++)
		window->draw(_menuTextItems[i]);
}
