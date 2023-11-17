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
            public:
                Fase1();
                ~Fase1();
                
                bool get_neve();

                void fim_de_jogo();
                void executar();
                void mover();
                void atualizar();
                void pausar();
                void menu();
        };
    }
}
