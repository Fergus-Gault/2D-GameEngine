#include "./Engine/GameEngine.h"
#include "./Utils/utils.h"
#include <iostream>

GameEngine::GameEngine(){}

// Init window with default values
bool GameEngine::init(const int x = 800, const int y = 600, const std::string& name = "2D Game Engine") {
	window_ = new sf::RenderWindow(sf::VideoMode(x, y), name);
	if (!window_) {
		std::cerr << "Failed to create window\n";
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
