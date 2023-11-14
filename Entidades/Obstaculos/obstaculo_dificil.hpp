#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo_Dificil : public Obstaculo
        {
            private:
                int cura;
            public:
                Obstaculo_Dificil(Vector2f pos = Vector2f(0.f, 0.f));
                ~Obstaculo_Dificil();

                int get_cura() {return cura;}
                
                void executar();
                void mover();
                void atualizar();
        };
    }
}