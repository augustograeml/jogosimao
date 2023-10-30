#include "inimigo.hpp"
#include <stdlib.h>
#include <math.h>

Inimigo::Inimigo() : maldade(false)
{
    int m = rand() % 6;
    if(m == 1)
        maldade = true;
    if(maldade)
        vida = 5;
    else
        vida = 10;

    pjogador = nullptr;
    corpo.setFillColor(sf::Color::Green);
    corpo.setPosition(sf::Vector2f(800.f, 800.f));
}

Inimigo::~Inimigo()
{

}

sf::Vector2f getPosicao()
{
    //corpo
}

void setPosicao(sf::Vector2f& p)
{
    this->posicao = p;

}

void Inimigo::update(sf::Vector2f& posicao_jogador)
{
    sf::Vector2f direcao = posicao_jogador - corpo.getPosition();
    float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    direcao /= comprimento;


}

