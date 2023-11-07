#include "jogador.hpp"
#include <iostream>
using namespace std;

Jogador::Jogador(Vector2f pos, Vector2f vel) : Personagem(pos, vel), tempo(0.0)
{
    corpo.setFillColor(Color::Red);
}
Jogador::~Jogador()
{

}

void Jogador::atualizar()
{
    corpo.setPosition(corpo.getPosition() + velocidade);
}

void Jogador::executar()
{
    mover();
}

void Jogador::mover()
{
        //valor normal = 0.3
        
       /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
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
        }*/
        if (!nochao)
                {
                    velocidade.y += 0.1f;
                //velocidade.y = 0;
                }
        else
        {   
            velocidade.y = 0.0f;
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                velocidade.x += 0.1f;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                velocidade.x += -0.1f;   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
                velocidade.y += -0.1f;    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                velocidade.y += 0.1f;  
            nochao = false;
        }

        corpo.setPosition(corpo.getPosition() + velocidade);

}
