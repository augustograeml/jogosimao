#include "jogador.hpp"
#include <iostream>
using namespace std;

Jogador::Jogador(Vector2f pos, Vector2f vel) : Personagem(pos, vel), tempo(0.0)
{
    corpo.setFillColor(Color::Green);
    this->setSkin("src/imagem/op1.png");
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

void Jogador::atacar()
{
}

void Jogador::mover()
{
    if (!nochao)            
        velocidade.y += 0.1f;

    else
        velocidade.y = 0.0f;
            
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
            velocidade.x += 0.1f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
            velocidade.x += -0.1f;   
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && nochao)
            velocidade.y += -5.0f;    
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
            velocidade.y += 0.1f;  
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
            atacar();  
        nochao = false;

        atualizar();
}
