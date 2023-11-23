#pragma once
#include "obstaculo.hpp"
#include "../Personagens/jogador.hpp"

namespace Entidades
{
    namespace Obstaculos
    {
        class Musgo : public Obstaculo
        {
            private:
                bool gosmento;
            public:
                Musgo(sf::Vector2f pos);
                ~Musgo();

                bool get_gosmento() {return gosmento;}
                void gosmar(Entidades::Personagens::Jogador* pJ);

                void executar();
                void mover();
                void atualizar();
                void colidir(Entidade* pE, int a);
        };
    }
}