#pragma once
#include "obstaculo.hpp"
#include "../Personagens/jogador.hpp"

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

                bool get_escorrega() {return escorrega;}
                void escorregar(Entidades::Personagens::Jogador* pJ);

                void executar();
                void mover();
                void atualizar();
                void colidir(Entidade* pE);
        };
    }
}