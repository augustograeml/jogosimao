#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {

        class Obstaculo_Medio : public Obstaculo
        {
            private:
                float dano;
            public:
                Obstaculo_Medio(Vector2f pos = Vector2(0.f, 0.f));
                ~Obstaculo_Medio();
                void executar();
                void mover();
                void atualizar();
        };

    }

}