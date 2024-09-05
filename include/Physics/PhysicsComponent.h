#pragma once

#include <SFML/Graphics.hpp>
#include "Utils/utils.h"

class GameObject;

class PhysicsComponent {
public:
	PhysicsComponent(const sf::Drawable& drawable) : drawable_(drawable) {}
	void update(GameObject& obj, Time deltaTime);

private:
	const sf::Drawable& drawable_;
};