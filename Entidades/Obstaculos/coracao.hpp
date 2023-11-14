#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Coracao : public Obstaculo
        {
            private:
                int cura;
            public:
                Coracao(Vector2f pos = Vector2f(0.f, 0.f));
                ~Coracao();

                int get_cura() {return cura;}
                
                void executar();
                void mover();
                void atualizar();
        };
    }
}