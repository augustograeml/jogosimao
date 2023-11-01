#include "jogador.hpp"

Jogador::Jogador()
{
    
}
Jogador::~Jogador()
{

}
void Jogador::mover()
{
        //valor normal = 0.3
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            corpo.move(sf::Vector2f(2.3,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            corpo.move(sf::Vector2f(-2.3,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            corpo.move(sf::Vector2f(0,-2.3));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            corpo.move(sf::Vector2f(0,2.3));
        }

}
