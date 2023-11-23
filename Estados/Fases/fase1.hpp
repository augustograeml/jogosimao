#pragma once
#include "fase.hpp"

namespace Estados
{
    namespace Fases
    {
        class Fase1 : public Fase
        {
            private:
                bool neve;
                int identidade;
            public:
                Fase1(int id);
                ~Fase1();
                
                bool get_neve();

                void fim_de_jogo();
                //colocar como parametro um bool pro jogador2, lembrar de mexer na clase virtual pura de fase.hpp
                void executar();
                void atualizar();
                void pausar();
                void menu();
        };
    }
}
