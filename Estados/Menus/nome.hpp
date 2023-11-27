#pragma once
#include "menu.hpp"
#include "textbox.hpp"
#include "../Fases/fase.hpp"

namespace Estados
{
    namespace Menus
    {
        class Nome : public Menu
        {
            private:
                std::string nome_jogador;
                int num_jog_ranking;
                Estados::Fases::Fase* pFase;
                Textbox Caixa;
            public:
                Nome(int id, Estados::Fases::Fase* pF = nullptr);
                ~Nome();

                void inicializa_valores();
                void loop_evento();
        };
    }
}