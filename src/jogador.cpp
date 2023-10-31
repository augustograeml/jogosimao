#include "jogador.hpp"

Jogador::Jogador()
{
    
}
Jogador::~Jogador()
{

}
void Jogador::mover()
{
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            setSkin("src/imagem/andando.png");
            corpo.move(sf::Vector2f(0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            setSkin("src/imagem/andando.png");
            corpo.move(sf::Vector2f(-0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            setSkin("src/imagem/andando.png");
            corpo.move(sf::Vector2f(0,-0.15));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            setSkin("src/imagem/andando.png");
            corpo.move(sf::Vector2f(0,0.15));
        }

}
