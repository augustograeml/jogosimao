#include "../Entidades/Obstaculos/obstaculo_dificil.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Obstaculo_Dificil::Obstaculo_Dificil(sf::Vector2f pos): Obstaculo(pos, true), cura(5)
        {
            this->setSkin("src/imagem/saude.png");
            this->set_vida(40);
        }

        Obstaculo_Dificil::~Obstaculo_Dificil()
        {

        }

        void Obstaculo_Dificil::executar()
        {
            
        }

        void Obstaculo_Dificil::mover()
        {
            
        }

        void Obstaculo_Dificil::atualizar()
        {
            
        }
    }
}