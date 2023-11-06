#include "jogador.hpp"
#include <iostream>

Jogador::Jogador() : Personagem(), tempo(0.0)
{
    corpo.setFillColor(Color::Red);
}
Jogador::~Jogador()
{

}

void Jogador::executar()
{
    std::cout << "estou me movendo \n"; 
    mover();
}

void Jogador::mover()
{
        //valor normal = 0.3
        
        /*if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            std::cout << " movendo para a direita \n";
            corpo.move(sf::Vector2f(2.3,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
             std::cout << " movendo para a esqierda \n";
            corpo.move(sf::Vector2f(-2.3,0));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
             std::cout << " movendo para cima \n";
            corpo.move(sf::Vector2f(0,-2.3));
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
             std::cout << " movendo para a baixo \n";
            corpo.move(sf::Vector2f(0,2.3));
        }*/
        if (!nochao)
                velocidade += sf::Vector2f(0, 0.1);  
            else
                velocidade = sf::Vector2f(velocidade.x, 0.f);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                velocidade += sf::Vector2f(0.1, 0);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                velocidade += sf::Vector2f(-0.1, 0);   
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && nochao)
                velocidade += sf::Vector2f(0, -5.f);    
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
                velocidade += sf::Vector2f(0, 0.1);  
            corpo.setPosition(corpo.getPosition() + velocidade);
            nochao = false;


}
