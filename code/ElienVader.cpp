#include <SFML/Graphics.hpp>

int main()
{
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

        window.clear();
        window.draw(shape);
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
    }

    return 0;
}