#include <SFML/Graphics.hpp>
#include <iostream>

class Player{
        float speed,positionX;
        int sizeX,lives;
    public:
        Player()
        {   
            lives=3;
            sizeX = 100;
            speed = 5.0f;
            positionX = 0.f;
        }

        void check_input();
        void move_player();
        void display_player();

};

void Player::display_player()
{
    sf::RectangleShape player({100, 50});
    
}

void Player::check_input()
{
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)))
    {
        std::cout<<"Aa"<<std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D) || (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)))
    {
        std::cout<<"BBB"<<std::endl;
    }
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        
    }
}

int main()
{
    Player player;
    sf::RenderWindow window(sf::VideoMode(1000, 1000), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setPosition({0, 200});

    sf::CircleShape shape1(100.f);
    shape1.setPosition({0, 400});

    sf::RectangleShape shape2({700, 200});
    shape2.setPosition({100, 300});

    sf::CircleShape shape3(100.f);
    shape3.setPosition({700, 300});

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        player.check_input();
        player.display_player();
        window.clear();
        window.draw(shape);
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
    }

    return 0;
}