#pragma once
#include "../entidade.hpp"
#include "../Personagens/jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Obstaculo : public Entidade
        {
            private:
                int intensidade;
            public:
                Obstaculo(Vector2f pos = Vector2f(0.f, 0.f));
                ~Obstaculo();

                int get_intensidade() {return intensidade;}

                virtual void executar() = 0;
                virtual void mover() = 0;
                virtual void atualizar() = 0;
                virtual void colidir(Entidade* pE, int a) = 0;
        };
    }
}