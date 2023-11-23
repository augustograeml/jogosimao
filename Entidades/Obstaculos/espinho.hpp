#pragma once
#include "obstaculo.hpp"
#include "../Personagens/jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Espinho : public Obstaculo
        {
            private:
                int dano;
            public:
                Espinho(Vector2f pos = Vector2(0.f, 0.f));
                ~Espinho();

                void espinhar(Entidades::Personagens::Jogador* pJ);
                void executar();
                int get_dano() {return dano;}
                void mover();
                void atualizar();
                void colidir(Entidade* pE,int a);
        };
    }
}