#include "../Entidades/Personagens/personagem.hpp"

namespace Entidades
{
    namespace Personagens
    {
        Personagem::Personagem(sf::Vector2f pos, sf::Vector2f vel) : Entidade()
        {
            corpo.setPosition(pos);
            velocidade = vel;
        }

        Personagem::~Personagem()
        {
            //vida = 0;
        }
    }
}