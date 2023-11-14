#include "../Entidades/Obstaculos/espinho.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Espinho::Espinho(sf::Vector2f pos) : Obstaculo(pos, true), dano(2.0)
        {
            this->setSkin("src/imagem/espinho.png");
            this->set_vida(55);
        }

        Espinho::~Espinho()
        {

        }

        void Espinho::executar()
        {

        }

        void Espinho::mover()
        {

        }

        void Espinho::atualizar()
        {

        }
    }
}