#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class GameEngine {
public:
	GameEngine();
	bool init(const int x, const int y, const std::string& name);
	void run();
	void pollEvents();
	void update(sf::Time deltaTime);

private:
	sf::RenderWindow* window_ = nullptr;
};