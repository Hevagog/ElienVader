#pragma once
#include "SFML/Graphics.hpp"
#include "Object.hpp"


class Object{

    Object();
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    private:
        sf::RectangleShape shape;
        void move();
        void kill();
    public:
        
};

Object::Object()
{

}

void draw(sf::RenderTarget& target, sf::RenderStates states)
{
    target.draw(shape,states);
}