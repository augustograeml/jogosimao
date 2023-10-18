#include <iostream>
using namespace std;

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "src/Product.hpp"

int main()
{
    Product processador = Product("Ryzem7", 1100.99);

    processador.printDetails();
    
    sf::RenderWindow window(sf::VideoMode(800, 600), "Janela SFML");
    window.setFramerateLimit(60);
    window.setVerticalSyncEnabled(true);


    bool gameLoop = true;
    while (gameLoop)
    {
        sf::Event event;

        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                gameLoop = false;
            }
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) // Tecla esc encerra o programa
            {
                gameLoop = false;
                window.close();
            }

        }
        window.clear(sf::Color::Cyan);

        window.display();
    }

    return EXIT_SUCCESS;
}
