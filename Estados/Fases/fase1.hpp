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
                int num_espinhos;
                int num_coracoes;
                int num_zumbi;
                int num_arqueiro;
            public:
                Fase1();
                ~Fase1();
                
                bool get_neve();

                void fim_de_jogo();
                void executar(bool jogador2);
                void mover();
                void atualizar();
        };
    }
}
