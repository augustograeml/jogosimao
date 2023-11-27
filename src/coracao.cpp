#include "../Entidades/Obstaculos/coracao.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Coracao::Coracao(sf::Vector2f pos): Obstaculo(pos), cura(10)
        {
            this->setSkin("Design/imagens/saude.png");
            int dificil = rand()%10;
            if(dificil == 7)
                cura = 5;
            cura =  cura * get_intensidade();
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
            pJ->set_vida(get_vida() + cura);
        }
        void Coracao::colidir(Entidade* pE, int a)
        {
            Entidades::Personagens::Jogador* aux = static_cast<Entidades::Personagens::Jogador*> (pE);
            curar(aux);
            morrer();
        }
    }
}