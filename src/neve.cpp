#include "../Entidades/Obstaculos/neve.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Neve::Neve(Vector2f pos): Obstaculo(pos), escorrega(true)
        {
            this->setSkin("Design/imagens/plataforma.png");
            escorrega = rand()%2;
        }

        Neve::~Neve()
        {

        }

        void Neve::executar()
        {
            
        }

        void Neve::mover()
        {
            
        }

        void Neve::atualizar()
        {
            
        }
        void Neve::escorregar(Entidades::Personagens::Jogador* pJ)
        {
            if(get_escorrega())
            {
                pJ->setVelocidade(Vector2f((pJ->getVelocidade().x * get_intensidade())/1.85f, pJ->getVelocidade().y));
            }
            else
            {
                pJ->setVelocidade(Vector2f((pJ->getVelocidade().x * get_intensidade())/1.99f, pJ->getVelocidade().y));
            }
        }
        void Neve::colidir(Entidade* pE, int a)
        {
            Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*> (pE);
            escorregar(aux);
        }
    }
}