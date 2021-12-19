#pragma once
#include "SFML/Graphics.hpp"

class Object : public sf::Drawable, public sf::Transformable
{
    public:
        Object();
        virtual void update(sf::Time dt) = 0;
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const = 0;
};

Object::Object() {
}
