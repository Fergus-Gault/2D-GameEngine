#pragma once

#include <SFML/Graphics.hpp>
#include <box2d/box2d.h>
#include <string>
#include <vector>

class GameObject;

class GameEngine {
public:
	GameEngine();
	bool init(const int x, const int y, const std::string& name);
	void run();
	void pollEvents();
	void update(sf::Time deltaTime);

	b2World* getWorld() const { return world_.get(); }
	sf::RenderWindow* getWindow() const { return window_.get(); }

private:
	std::unique_ptr<sf::RenderWindow> window_;
	std::unique_ptr<b2World> world_;

	// All objects in game
	std::vector<std::unique_ptr<GameObject>> objects_;
};