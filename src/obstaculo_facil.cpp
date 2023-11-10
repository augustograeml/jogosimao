#include "../Entidades/Obstaculos/obstaculo_facil.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo_Facil::Obstaculo_Facil(Vector2f pos): Obstaculo(pos, false)
        {
            corpo.setFillColor(sf::Color::Transparent);
        }

        Obstaculo_Facil::~Obstaculo_Facil()
        {

        }

        void Obstaculo_Facil::executar()
        {
            
        }

        void Obstaculo_Facil::mover()
        {
            
        }

        void Obstaculo_Facil::atualizar()
        {
            
        }
    }
}