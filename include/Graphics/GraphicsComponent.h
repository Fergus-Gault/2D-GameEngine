#pragma once

#include <SFML/Graphics.hpp>

class GraphicsComponent {
public:
    GraphicsComponent(const sf::Drawable& drawable) : drawable_(drawable) {}

    void draw(sf::RenderWindow& window) const {
        window.draw(drawable_);
    }

private:
    // Drawable being anything that can be drawn to the screen
    const sf::Drawable& drawable_;
};