#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo_Dificil : public Obstaculo
        {
            private:
                float dano;
            public:
                Obstaculo_Dificil(Vector2f pos = Vector2f(0.f, 0.f));
                ~Obstaculo_Dificil();
                void executar();
                void mover();
                void atualizar();
        };
    }
}