#pragma once
#include "SFML/Graphics.hpp"

#include "Object.hpp"

#include <vector>
#include <memory>

class Player : public Object {
    public: 
        enum Actions {
            None,
            MoveRight,
            MoveLeft,
        };
    public:
        Player();
        virtual void update(sf::Time dt);
        void handleEvent(const sf::Event& event);
    private:
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        //void check_impact();//cooldown starts from impact ~1 
    private: 
        sf::ConvexShape shape;
        Actions action;
        std::vector<std::unique_ptr<Projectile>> projectiles;
        float speed;
        int lives;
        int cooldown;
};

Player::Player() : speed(10000.f), lives(3), cooldown(60)
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
    Transformable::setPosition({0, 960});
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(shape, states);
    for (const auto& bullet : projectiles)
        target.draw(*bullet, states);
}

void Player::update(sf::Time dt) 
{
    shape.setPosition(Transformable::getPosition());
    switch (action) {
        case MoveLeft:
            Transformable::move(sf::Vector2f(-speed, 0) * dt.asSeconds());
            break;
        case MoveRight:
            Transformable::move(sf::Vector2f(speed, 0) * dt.asSeconds());
            break;
    }
    action = None;
    //for (auto& bullet : projectiles)
    //    bullet->update(dt);
}

void Player::handleEvent(const sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::A) {
            action = MoveLeft;
        }
        if (event.key.code == sf::Keyboard::Key::D) {
            action = MoveRight;
        }
        if (event.key.code == sf::Keyboard::Key::Space && cooldown) {
            //projectiles.push_back(std::make_unique<Projectile>()); 
        }
    }
}

// void Player::check_colision(int width)
// {
//     if(positionX+sizeX>=width){
//         positionX -= 1*speed;
//     }
//      if(positionX<=0){
//         positionX += 1*speed;
//     }
// }