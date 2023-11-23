#include "../Entidades/Obstaculos/coracao.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Coracao::Coracao(sf::Vector2f pos): Obstaculo(pos,false, true, false,false,false), cura(20)
        {
            this->setSkin("Design/imagens/saude.png");
            //this->set_vida(40);
        }

        Coracao::~Coracao()
        {

        }

        void Coracao::executar()
        {
            
        }

        void Coracao::mover()
        {
            
        }

        void Coracao::atualizar()
        {
            
        }
        void Coracao::curar(Entidades::Personagens::Jogador* pJ)
        {
            pJ->set_vida(cura);
        }
        void Coracao::colidir(Entidade* pE)
        {
            Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*> (pE);
            curar(aux);
        }
    }
}