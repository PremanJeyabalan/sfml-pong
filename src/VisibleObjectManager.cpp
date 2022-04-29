#include "VisibleObjectManager.h"
#include <chrono>
//float VisibleObjectManager::total_seconds = 0.0f;
//int VisibleObjectManager::total_count = 0;

VisibleObjectManager::~VisibleObjectManager() {
	auto it = _objects.begin();

	while (it != _objects.end()) {
		delete it->second;
		++it;
	}
}

void VisibleObjectManager::add(std::string&& name,VisibleObject* object) {
	_objects.insert(std::pair<std::string, VisibleObject*>(name, object));
}

void VisibleObjectManager::remove(std::string&& name) {
	auto results = _objects.find(name);
	if (results != _objects.end()) {
		delete results->second;
		_objects.erase(results);
	}
}

VisibleObject* VisibleObjectManager::get(std::string&& name) {
	auto results = _objects.find(name);
	
	if (results == _objects.end()) return NULL;

	return results->second;
}

void VisibleObjectManager::handleInputAll(sf::Event* event) {
	auto itr = _objects.begin();

	while (itr != _objects.end()) {
		itr->second->handleInput(event);
		itr++;
	}
}

void VisibleObjectManager::updateAll(float timeElapsed) {
	//auto start = std::chrono::high_resolution_clock::now();
	auto itr = _objects.begin();

	while (itr != _objects.end()) {
		itr->second->update(timeElapsed);
		itr++;
	}

	//Detect collision
	auto originItr = _objects.begin();

	while (originItr != _objects.end()) {
		sf::Rect<float> originBound = originItr->second->getBoundingRect();

		auto targetItr{ originItr };

		targetItr++;

		while (targetItr != _objects.end()) {
			if (targetItr == originItr) { targetItr++; continue; }

			sf::Rect<float> targetBound = targetItr->second->getBoundingRect();

			if (originBound.intersects(targetBound)) {
				originItr->second->collideWith(targetItr->second);
				targetItr->second->collideWith(originItr->second);
			}


			targetItr++;
		}

		originItr++;

	}
	/*auto stop = std::chrono::high_resolution_clock::now();
	VisibleObjectManager::total_seconds += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	VisibleObjectManager::total_count++;

	std::cout << total_seconds / total_count << std::endl;*/

}

void VisibleObjectManager::updateAllDP(float timeElapsed) {
	//auto start = std::chrono::high_resolution_clock::now();
	auto itr = _objects.begin();

	while (itr != _objects.end()) {
		itr->second->update(timeElapsed);
		itr++;
	}

	//Detect collision
	auto originItr = _objects.begin();

	while (originItr != _objects.end()) {
		sf::Rect<float> originBound = originItr->second->getBoundingRect();

		auto targetItr = _objects.begin();

		while (targetItr != _objects.end()) {
			if (targetItr == originItr) { targetItr++; continue; }

			sf::Rect<float> targetBound = targetItr->second->getBoundingRect();

			if (originBound.intersects(targetBound))
				originItr->second->collideWith(targetItr->second);

			targetItr++;
		}

		originItr++;

	}
	//auto stop = std::chrono::high_resolution_clock::now();
	//VisibleObjectManager::total_seconds += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
	//VisibleObjectManager::total_count++;

	//std::cout << total_seconds / total_count << std::endl;
}

void VisibleObjectManager::drawAll(sf::RenderWindow* window) {
	auto itr = _objects.begin();

	while (itr != _objects.end()) {
		itr->second->draw(window);
		itr++;
	}
}