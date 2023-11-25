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
                clock_t tempoinicio;
                double tempo_fase2;
            public:
                Fase2(int id);
                ~Fase2();
                bool get_musgos();

                void executar();
                void fim_de_jogo();
                void atualizar();
        };
    }
}