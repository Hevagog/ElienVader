#include <SFML/Graphics.hpp>
#include <iostream>



class Player : public sf::Drawable {
        float speed;
        int lives;
    public:
        float sizeX,positionX;
        Player()
        {   
            lives=3;
            sizeX = 50;
            speed = 20.0f;
            positionX = 500-sizeX/2;
        }
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void process_events(sf::Event& event);
        void check_colision(int width);
        void process_event(sf::Event event);
};

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    sf::RectangleShape a({sizeX, sizeX/2});
    a.setPosition(positionX,950);
    target.draw(a, states);
}

void Player::process_event(sf::Event event)
{
    if (event.type == sf::Event::KeyPressed) {
        if (event.key.code == sf::Keyboard::Key::A) {
            positionX-=1*speed;
        }
        if (event.key.code == sf::Keyboard::Key::D) {
            positionX+=1*speed;
        }
        if (event.key.code == sf::Keyboard::Key::Space) {
            //Do something
        }
    }
}

void Player::check_colision(int width)
{
    if(positionX+sizeX>=width){
        positionX -= 1*speed;
    }
     if(positionX<=0){
        positionX += 1*speed;
    }
}

class Enemy : public sf::Drawable, public Player{
    //TODO
};

class Game
{
    private:
        static const int window_width  = 1000;
        static const int window_height = 1000;
        sf::RenderWindow window;
        Player player;
    public:
        Game(): window(sf::VideoMode(1000,1000),"ElienVader", sf::Style::Close)
        {
        }
        void run();
        void process_event();
};


void Game::run(){
    
    while (window.isOpen())
    {
        process_event();
        player.check_colision(window_width);
        window.clear();
        window.draw(player);
        window.display();
    }
    
}

void Game::process_event(){
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
        player.process_event(event);
    }
}

int main()
{
    Game game;
    game.run();
    return 0;
}