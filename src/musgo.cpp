#include "../Entidades/Obstaculos/musgo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        Musgo::Musgo(sf::Vector2f pos) : Obstaculo(pos, false), gosmento(false)
        {
            this->setSkin("Design/imagens/bloco_musgo.jpeg");
            this->set_vida(1);
        }

        Musgo::~Musgo()
        {

        }

        void Musgo::mover()
        {

        }

        void Musgo::executar()
        {

        }

        void Musgo::atualizar()
        {

        }        
    }
}