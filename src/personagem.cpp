#include "../Entidades/Personagens/personagem.hpp"

using namespace Entidades;
using namespace Personagens;

Personagem::Personagem(Vector2f pos, Vector2f vel) : Entidade()
{
    corpo.setPosition(pos);
    velocidade = vel;
}

Personagem::~Personagem()
{
    //vida = 0;
}