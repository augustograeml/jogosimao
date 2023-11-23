#pragma once
#include "obstaculo.hpp"
#include "../Personagens/jogador.hpp"

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
                
                void curar(Entidades::Personagens::Jogador* pJ);
                void executar();
                void mover();
                void atualizar();
                void colidir(Entidade* pE, int a);
               
        };
    }
}