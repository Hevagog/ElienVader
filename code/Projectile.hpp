#pragma once
#include "SFML/Graphics.hpp"
#include "Object.hpp"

class Projectile : public Object{
    private:
        float speed,radius,damage;
        bool side;
        
    public:
        Projectile(bool is_my_side,float initial_x,float initial_y);
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
        virtual void update(sf::Time dt) override;

        bool impact();        
        sf::CircleShape shape;
};

Projectile::Projectile(bool is_my_side,float initial_x,float initial_y) : speed(1000.f), damage(1),radius(5.0f)
{ 
    side = is_my_side;
    shape.setRadius (radius);
    Transformable::setPosition(initial_x,initial_y);
}

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape,states);
}

bool Projectile::impact()
{
    float pos_y = Transformable::getPosition().y;
    return (pos_y>=1000||pos_y<0) ? true : false;
}

void Projectile::update(sf::Time dt)
{
    shape.setPosition(Transformable::getPosition());
    if(side)
        Transformable::move(sf::Vector2f(0, -speed) * dt.asSeconds());
    else
        Transformable::move(sf::Vector2f(0, speed) * dt.asSeconds());
}