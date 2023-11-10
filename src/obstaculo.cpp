#include "../Entidades/Obstaculos/obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos, bool dano) :
        Entidade(pos), danoso(dano)
        {

        }

        Obstaculo::~Obstaculo()
        {

        }
    }
}