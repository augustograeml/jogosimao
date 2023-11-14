#pragma once

#include "menu.hpp"
#include "../../Observers/observer_tecla.hpp"

namespace Estados
{
    namespace Menu
    {
        class Menu_Principal : public Menu
        {
            private:
                //fundo
                bool sair;
                Observers::Observer_Tecla observer_menu_principal;
            public:
                Menu_Principal();
                ~Menu_Principal();
                void criar_fundo();
                void criar_botoes();
                void set_sair(bool sair);
                bool get_sair();
                void mudar_estado_observador();
                void executar();
        };
    }
}