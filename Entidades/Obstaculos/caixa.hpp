#pragma once
#include "obstaculo.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Caixa : public Obstaculo
        {
            private:
                bool atrapalha;
            public:
                Caixa(Vector2f pos = Vector2f(0.f, 0.f));
                ~Caixa();

                void criar_caixas(string arquivo);

                void executar();
                void mover();
                void atualizar();
                void colidir(Entidade* pE, int a);
        };
    }
}