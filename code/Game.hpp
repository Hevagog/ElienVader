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
        void adaptPlayerPosition();
    private:
        static const int window_width  = 1000;
        static const int window_height = 1000;
        sf::RenderWindow window; 
        std::vector<std::unique_ptr<Object>> enemies;
        Player player;
};

Game::Game(): window(sf::VideoMode(window_width, window_height),"ElienVader", sf::Style::Close)
{
}

void Game::run(){
    sf::Clock clock;
    const sf::Time TimePerFrame = sf::seconds(1.f / 60.f);
    sf::Time timeSinceLastUpdate = sf::Time::Zero;

    while (window.isOpen())
    {
        sf::Time dt = clock.restart();
        timeSinceLastUpdate += dt;
        while (timeSinceLastUpdate > TimePerFrame) {
            timeSinceLastUpdate -= TimePerFrame;
            process_event();
            update(dt);
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
    adaptPlayerPosition();
}

void Game::draw() {
    window.clear();
    window.draw(player);
    //for (const auto& obj : enemies) {
    //    window.draw(obj);
    //}
    window.display();   
}

void Game::adaptPlayerPosition() {
	sf::Vector2f position = player.getPosition();
	position.x = position.x < 0 ? 0 : position.x;
	position.x = position.x > window_width ? window_width : position.x;
	player.setPosition(position);
}