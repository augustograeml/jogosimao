#pragma once

#include "menu.hpp"
#include "../../Observers/observer_tecla.hpp"

namespace Estados
{
    namespace Menus
    {
        class Menu_Principal : public Menu
        {
            private:
                int estagio_atual;
                int jogador_atual;

                Texto estagio1;
                Texto estagio2;

                Texto jogador1;
                Texto jogador2;

            public:
                Menu_Principal();
                ~Menu_Principal();
                void selecionar();
                void mover_horizontalmente(int i);
                void desenhar();
        };
    }
}