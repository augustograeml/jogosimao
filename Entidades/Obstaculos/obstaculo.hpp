#pragma once
#include "../entidade.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
            private:
                bool danoso;
            public:
                Obstaculo(Vector2f pos = Vector2f(0.f, 0.f), bool dano = false);
                ~Obstaculo();
                
                virtual void executar() = 0;
                virtual void mover() = 0;
                virtual void atualizar() = 0;
        };
    }
}