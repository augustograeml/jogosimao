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
                int num_espinhos;
                int num_coracoes;
                int num_zumbi;
                int num_arqueiro;
                int num_obstaculo_novo;
            public:
                Fase2();
                ~Fase2();
                bool get_musgos();

                void executar();
                void fim_de_jogo();
                void atualizar();
                void pausar();
                void menu();
        };
    }
}