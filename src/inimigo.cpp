#include "../Entidades/Personagens/inimigo.hpp"
#include <stdlib.h>
#include <math.h>

using namespace Entidades;
using namespace Personagens;

Inimigo::Inimigo(Vector2f pos, Vector2f vel) : Personagem(pos, vel), maldade(false), pjogador(nullptr)
{
    int m = rand() % 6;
    if(m == 1)
        maldade = true;
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
