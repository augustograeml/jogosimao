#pragma once
#include "menu.hpp"
#include "textbox.hpp"

namespace Estados
{
    namespace Menus
    {
        class Nome : public Menu
        {
            private:
                std::string nome_jogador;
                int num_jog_ranking;
                Textbox Caixa;
            public:
                Nome(int id);
                ~Nome();

                void inicializa_valores();
                void loop_evento();
        };
    }
}