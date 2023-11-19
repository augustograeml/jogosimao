#include "../Entidades/Obstaculos/caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(sf::Vector2f pos) : Obstaculo(pos, false), atrapalha(false)
        {
            int i = rand()%10;
            if(i == 2)
                atrapalha = true;

            this->setSkin("Design/imagens/caixa.png");
            this->set_vida(20);
        }

        Caixa::~Caixa()
        {

        }

        void Caixa::executar()
        {
            
        }

        void Caixa::mover()
        {
            
        }

        void Caixa::atualizar()
        {
            
        }
    }
}