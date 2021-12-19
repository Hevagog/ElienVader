#pragma once
#include "SFML/Graphics.hpp"

class Projectile : public sf::Drawable{
        float speed,radius,dmg;
        float positionY,positionX;
        bool side;
    public:
        Projectile(float damage,float initial_position,bool is_my_side)
        {
            positionX = initial_position;
            positionY = 0;
            speed = 18.0f;
            radius = 5.0;
            dmg = damage;
            side = is_my_side;
        }
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void move();// maybe move to draw function??
        void impact(); // _logic & functionality TBD_
};

void Projectile::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::CircleShape p(radius);
    p.setPosition(positionX,positionY);
    target.draw(p,states);
}

void Projectile::move()
{
    if(side)
        positionY += 1*speed;
    else
        positionY -= 1*speed;
}
void Projectile::impact()
{
    //delete projectile;
    //if(positionY>=1000||positionY<=0)
}