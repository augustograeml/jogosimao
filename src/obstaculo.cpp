#include "../Entidades/Obstaculos/obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(Vector2f pos, bool dano) :
        Entidade(pos), danoso(dano)
        {

        }

        Obstaculo::~Obstaculo()
        {

        }
    }
}