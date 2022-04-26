#include "GameState.h"

GameState::~GameState() {};

VisibleObjectManager* GameState::getObjectManager() {
	return &_visibleObjectManager;
}
