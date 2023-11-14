#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho : public Obstaculo
        {
            private:
                float dano;
            public:
                Espinho(Vector2f pos = Vector2(0.f, 0.f));
                ~Espinho();
                void executar();
                void mover();
                void atualizar();
        };
    }
}