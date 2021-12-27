#pragma once
#include "Object.hpp"
#include "SFML/Graphics.hpp"
#include "Projectile.hpp"
#include <random>
class Enemy : public Object {
    public:
        bool pushBackBullet;
    private:
        float speed,range,offset_x;
        int random;
        bool direction;
    public:
        Enemy(/*float posX*/);
        sf::ConvexShape shape;
        virtual void update(sf::Time dt) override;   
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
       // std::vector<std::unique_ptr<Projectile>> projectiles;//Fur genau
        void attack();
};

Enemy::Enemy(/*int offset_x*/) : speed( 300.f), range(1000.f), direction(true)
{
    shape.setPointCount(8);
    shape.setPoint(0, {0, 30});
    shape.setPoint(1, {0, 10});
    shape.setPoint(2, {10, 10});
    shape.setPoint(3, {10, 0});
    shape.setPoint(4, {20, 0});
    shape.setPoint(5, {20, 10});
    shape.setPoint(6, {30, 10});
    shape.setPoint(7, {30, 30});
    Transformable::setPosition({0,20});
}

void Enemy::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape,states);
}

void Enemy::attack()
{
    std::uniform_real_distribution<double> distribution(1, 1500);
    std::random_device rd;
    std::default_random_engine generator(rd());
    random = distribution(generator);
    if(random>1495){
        pushBackBullet =1;
        // projectiles.push_back(std::make_unique<Projectile>
        // (false,Transformable::getPosition().x+10)); 
    }
}
void Enemy::update(sf::Time dt)
{   
    shape.setPosition(Transformable::getPosition());
    if(Transformable::getPosition().x < 0 ){
        direction = true;
        Transformable::move(sf::Vector2f(0,20));
    }
    if(Transformable::getPosition().x+30 > 1000){
        direction = false;
        Transformable::move(sf::Vector2f(-10,20));
    }
    
    if(direction)
    {
        Transformable::move(sf::Vector2f(speed, 0) * dt.asSeconds()); 
    }else if(!direction)
    {
        Transformable::move(sf::Vector2f(-speed, 0) * dt.asSeconds()); 
    }
}
