#pragma once
#include "Object.hpp"
#include "SFML/Graphics.hpp"

class Enemy {
    Enemy();
    int lives;
    float speed;
    
    void attack();
};

Enemy::Enemy()
{
    lives=0;
    speed = 15.0f;
}


void Enemy::attack()
{

}
