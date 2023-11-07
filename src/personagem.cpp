#include "personagem.hpp"

Personagem::Personagem(Vector2f pos, Vector2f vel) : Entidade(), vidas(1)
{
    corpo.setPosition(pos);
    velocidade = vel;
}

Personagem::~Personagem()
{
    vidas = 0;
}