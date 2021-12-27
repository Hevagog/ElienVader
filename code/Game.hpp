#pragma once
#include "SFML/Graphics.hpp"
#include "Projectile.hpp"
#include "Player.hpp"
#include "Enemy.hpp"

class Game
{
    public:
        Game();
        void run();
        void process_event();
        void update(sf::Time dt);
        void draw();
    private:
        void checkCollision(sf::Time dt);
        void adaptPlayerPosition();
        void handleProjectiles();
    private:
        static const int window_width  = 1000;
        static const int window_height = 1000;
        sf::RenderWindow window; 
        std::vector<std::unique_ptr<Projectile>> projectiles;
        std::vector<std::unique_ptr<Enemy>> enemies;
        //  Enemy enemy;
        Player player;
};

Game::Game(): window(sf::VideoMode(window_width, window_height),"ElienVader", sf::Style::Close)
{ 
}

void Game::run(){
    sf::Clock clock;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    enemies.push_back(std::make_unique<Enemy>());    
    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            process_event();
            update(TimePerFrame);
        }
        draw();
    }
}

void Game::process_event(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        player.handleEvent(event);
    }
}

void Game::update(sf::Time dt) {
    player.update(dt);
    for (auto &enemy : enemies){
        enemy->update(dt);
        enemy->attack();
    }
    for(auto &bullet : projectiles)
        bullet->update(dt);
    adaptPlayerPosition();
    handleProjectiles();
    // checkCollision();
}

void Game::draw() {
    window.clear();
    window.draw(player);
    for(auto &enemy : enemies)
        window.draw(*enemy);
    for(auto &bullet : projectiles)
        window.draw(*bullet);
    //    window.draw(obj);
    //}
    window.display();   
}

void Game::adaptPlayerPosition() {
	sf::Vector2f position = player.getPosition();
	position.x = position.x < 0 ? 0 : position.x;
	position.x = position.x+30 > window_width ? window_width-30 : position.x;
    
	player.setPosition(position);
}

void Game::checkCollision(sf::Time dt){
  for(int i =0;i<projectiles.size();i++)
    {
        projectiles[i]->update(dt);
        if(projectiles[i]->impact()){
            projectiles[i].release();
            projectiles.erase(projectiles.begin()+i);
        }
    }  
}

void Game::handleProjectiles(){
    if (player.pushBackBullet){
        projectiles.push_back(std::make_unique<Projectile>(true,player.getPosition().x+10,player.getPosition().y));
        player.pushBackBullet =0; 
    }
    for(auto &enemy : enemies)
        if(enemy->pushBackBullet){
            projectiles.push_back(std::make_unique<Projectile>(false,enemy->getPosition().x+10,enemy->getPosition().y));
            enemy->pushBackBullet =0;       
        }
    
}