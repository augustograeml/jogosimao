#include "jogo.hpp"

Jogo::Jogo(): window(sf::VideoMode(800, 800), "Mario x Luigi"),
    shape(sf::Vector2f(100.f,100.f)), shape2(sf::Vector2f(100.f,100.f))
{
    texturaPersonagem.loadFromFile("imagem/mario.png");
    texturaPersonagem2.loadFromFile("imagem/luigiDireita.png");
    shape.setTexture(&texturaPersonagem);
    shape2.setTexture(&texturaPersonagem2);

    Executar();
}

void Jogo::Executar()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shape.move(sf::Vector2f(0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            shape.move(sf::Vector2f(-0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            shape.move(sf::Vector2f(0,-0.15));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            shape.move(sf::Vector2f(0,0.15));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
        {
            shape2.move(sf::Vector2f(0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
        {
            shape2.move(sf::Vector2f(-0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            shape2.move(sf::Vector2f(0,-0.15));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
        {
            shape2.move(sf::Vector2f(0,0.15));
        }
        

        window.clear();
        window.draw(shape);
        window.draw(shape2);
        window.display();
    }
}