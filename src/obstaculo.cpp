#include "../Entidades/Obstaculos/obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo::Obstaculo(sf::Vector2f pos) :
        Entidade(pos),  intensidade(1)
        {
            intensidade = rand()%2 + 1;
        }

        Obstaculo::~Obstaculo()
        {

        }
        
    }
}