#include "../Entidades/Personagens/personagem.hpp"

Personagem::Personagem(Vector2f pos, Vector2f vel) : Entidade()
{
    corpo.setPosition(pos);
    velocidade = vel;
}

Personagem::~Personagem()
{
    //vida = 0;
}