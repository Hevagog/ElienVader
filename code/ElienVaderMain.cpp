#include <SFML/Graphics.hpp>
#include <iostream>

#include "Game.hpp"

int main()
{
    try {
        Game game;
        game.run();
    }
    catch (std::exception& exe) {
        std::cout << exe.what() << std::endl;
    }
    
    return 0;
}