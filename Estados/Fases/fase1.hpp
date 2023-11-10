#pragma once
#include "fase.hpp"
#define ARQUIVO_CENARIO_1 "src/cenario1.txt"

namespace Estados
{
    namespace Fases
    {
        class Fase1 : public Fase
        {
            private:
            public:
                Fase1();
                ~Fase1();
                
                void executar();
                void mover();
                void atualizar();
        };
    }
}
