#include "../Entidades/Obstaculos/caixa.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Caixa::Caixa(sf::Vector2f pos) : Obstaculo(pos), atrapalha(false)
        {
            int i = rand()%10;
            if(i == 2)
                atrapalha = true;
            this->set_vida(2 + get_intensidade());

            //se o jogador pular em cima da caixa e ela for fragil ela quebra

            this->setSkin("Design/imagens/caixa.png");
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
        void Caixa::colidir(Entidade* pE, int a)
        {
            if(!atrapalha)
            {
                if(a == 4 || a == 2)
                {
                    if(this->get_vida() >  0)
                    {
                        this->set_vida(this->get_vida() - 1);
                        this->setSkin("Design/imagens/caixa_quebrada.png");
                    }
                    else
                    this->set_vivo(0);
                }
            }
        }
    }
}