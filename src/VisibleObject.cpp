#include "VisibleObject.h"

VisibleObject::VisibleObject(std::string&& textureFileName) {

	if (!_texture.loadFromFile(textureFileName)) {
		std::cout << "Error loading assets from file" << std::endl;
		_isLoaded = false;
		return;
	}

	_sprite.setTexture(_texture);
	_isLoaded = true;

}

VisibleObject::~VisibleObject() {}

void VisibleObject::draw(sf::RenderWindow* window) {
	if (_isLoaded)
		window->draw(_sprite);
}

void VisibleObject::move(float x, float y) {
	_sprite.move(x, y);
}

void VisibleObject::setPosition(float x, float y) {
	_sprite.setPosition(x, y);
}

sf::Vector2<float> VisibleObject::getPosition() {
	return _sprite.getPosition();
}

float VisibleObject::getTop() {

	auto boundingRect = getBoundingRect();
	return boundingRect.top;
}

float VisibleObject::getBottom() {

	auto boundingRect = getBoundingRect();
	return boundingRect.top + boundingRect.height;
}

float VisibleObject::getLeft() {
	
	auto boundingRect = getBoundingRect();
	return boundingRect.left;
}

float VisibleObject::getRight() {
	
	auto boundingRect = getBoundingRect();
	return boundingRect.left + boundingRect.width;
}

sf::Rect<float> VisibleObject::getBoundingRect() {
	return _sprite.getGlobalBounds();
}
