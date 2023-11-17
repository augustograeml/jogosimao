#pragma once 
#include "fase.hpp"

namespace Estados
{
    namespace Fases
    {
        class Fase2 : public Fase
        {
            private:
                bool musgos;
            public:
                Fase2();
                ~Fase2();
                bool get_musgos();

                void executar();
                void fim_de_jogo();
                void mover();
                void atualizar();
                void pausar();
                void menu();
        };
    }
}