#pragma once
#include "Graphics/GraphicsComponent.h"
#include "Physics/PhysicsComponent.h"
#include "Utils/utils.h"
#include <memory>


class GameObject {
public:
    GameObject(sf::Drawable& obj)
        : graphicsComponent_(std::make_unique<GraphicsComponent>(obj))
        , physicsComponent_(std::make_unique<PhysicsComponent>(obj))
    {}

    void render(sf::RenderWindow& window) const {
        if (graphicsComponent_) {
            graphicsComponent_->draw(window);
        }
    }

    void update(Time deltaTime) {
        if (physicsComponent_) {
            physicsComponent_->update(*this, deltaTime);
        }
    }

    // Other game object methods...

private:
    std::unique_ptr<GraphicsComponent> graphicsComponent_;
    std::unique_ptr<PhysicsComponent> physicsComponent_;
};