#include <SFML/Graphics.hpp>
#include <iostream>

class Projectile : public sf::Drawable{
        float speed,radius,dmg;
        int positionY,positionX;
        bool side;
    public:
        Projectile(float damage,int initial_position,bool is_my_side)
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
        positionY += 1.0*speed;
    else
        positionY -= 1.0*speed;
}
void Projectile::impact()
{
    //if(positionY>=1000||positionY<=0)
}

class Player : public sf::Drawable {
        float speed;
        int lives;
        bool cooldown;
    public:
        float sizeX,positionX;
        bool shot;
        Player()
        {   
            shot  = 0;
            lives = 3;
            sizeX = 50;
            speed = 20.0f;
            positionX = 500-sizeX/2;
            cooldown=1;//TO BE MODIFIED
        }
        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
        void process_events(sf::Event& event);
        void check_colision(int width);
        void process_event(sf::Event event);
        //void check_impact();//cooldown starts from impact ~1 
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
        if (event.key.code == sf::Keyboard::Key::Space && cooldown) {
            shot=1;            
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