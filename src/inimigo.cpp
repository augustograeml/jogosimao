#include "inimigo.hpp"
#include <stdlib.h>
#include <math.h>

Inimigo::Inimigo() : maldade(false), pjogador(nullptr)
{
    int m = rand() % 6;
    if(m == 1)
        maldade = true;

    corpo.setFillColor(sf::Color::Green);
    corpo.setPosition(sf::Vector2f(800.f, 800.f));
}

Inimigo::~Inimigo()
{
    pjogador = nullptr;
}

sf::Vector2f Inimigo::getPosicao()
{
    return (corpo.getPosition());
}

void Inimigo::setPosicao(sf::Vector2f& p)
{
    this->posicao = p;
}

void Inimigo::update(sf::Vector2f& posicao_jogador)
{
    sf::Vector2f direcao = posicao_jogador - getPosicao();
    float comprimento = sqrt(direcao.x * direcao.x + direcao.y * direcao.y);
    direcao /= comprimento;

}
void Inimigo::executar()
{

}

