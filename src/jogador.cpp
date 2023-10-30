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
            corpo.move(sf::Vector2f(0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            corpo.move(sf::Vector2f(-0.15,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            corpo.move(sf::Vector2f(0,-0.15));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            corpo.move(sf::Vector2f(0,0.15));
        }
}
/*
void Jogador::getPosition()
{
    return corpo.getPosition()
}
*/
