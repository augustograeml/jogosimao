#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Neve : public Obstaculo
        {
            private:
                bool escorrega;
            public:
                Neve(Vector2f pos = Vector2f(0.f, 0.f));
                ~Neve();

                bool get_escorrega();

                void executar();
                void mover();
                void atualizar();
        };
    }
}