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
                void executar();
                void atualizar();
        };
    }
}
