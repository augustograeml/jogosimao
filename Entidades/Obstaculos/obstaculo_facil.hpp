#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo_Facil : public Obstaculo
        {
            private:
        
            public:
                Obstaculo_Facil(Vector2f pos = Vector2f(0.f, 0.f));
                ~Obstaculo_Facil();
                void executar();
                void mover();
                void atualizar();
        };
    }
}