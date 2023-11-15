#include "../Entidades/Obstaculos/coracao.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Coracao::Coracao(sf::Vector2f pos): Obstaculo(pos, true), cura(5)
        {
            this->setSkin("src/imagem/saude.png");
            this->set_vida(40);
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
    }
}