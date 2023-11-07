#include "jogador.hpp"
#include <iostream>

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
                velocidade = velocidade + sf::Vector2f(0, 0.1);  
        else
        {   
            velocidade = sf::Vector2f(velocidade.x, 0.f);
            
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                velocidade = velocidade + Vector2f(0.1, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                velocidade = velocidade + sf::Vector2f(-0.1, 0);   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && nochao)
                velocidade = velocidade + sf::Vector2f(0, -5.f);    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                velocidade = velocidade + sf::Vector2f(0, 0.1);  
            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;
        }

}
