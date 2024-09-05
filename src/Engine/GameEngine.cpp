#include "./Engine/GameEngine.h"
#include "./Engine/GameObject.h"
#include "./Utils/utils.h"
#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <iostream>
#include <memory>
#include <vector>


GameEngine::GameEngine(){}

// Init window with default values
bool GameEngine::init(const int x = 800, const int y = 600, const std::string& name = "2D Game Engine") {
	window_ = std::make_unique<sf::RenderWindow>(sf::VideoMode(x, y), name);
	if (!window_) {
		std::cerr << "Failed to create window\n";
		return false;
	}

	world_ = std::make_unique<b2World>(b2Vec2(0.0f, -9.8f));
	if (!world_) {
		std::cerr << "Failed to create Box2D world\n";
		return false;
	}


	return true;
}

// Main loop
void GameEngine::run() {
	Clock clock;
	while (window_->isOpen()) {
		pollEvents();
		update(clock.restart());
	}
}

// Event poller
void GameEngine::pollEvents() {
	sf::Event event;
	while (window_->pollEvent(event)) {
		if (event.type == sf::Event::Closed) {
			window_->close();
		}
	}
}


// Update within main loop
void GameEngine::update(Time deltaTime) {
	window_->clear();
	
	// Add rendering here

	// Update every object
	for (const auto& obj : objects_) {
		obj->render(*window_);
	}

	window_->display();
}


// Main
int main() {
	GameEngine engine;
	if (!engine.init()) {
		return -1;
	}
	engine.run();

	return 0;
}
