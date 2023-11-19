#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Musgo : public Obstaculo
        {
            private:
                bool gosmento;
            public:
                Musgo(sf::Vector2f pos);
                ~Musgo();

                bool get_gosmento();

                void executar();
                void mover();
                void atualizar();
        };
    }
}